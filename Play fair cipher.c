#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];
char cipherText[1000];
int cipherIndex = 0;
void createMatrix(char input[]) {
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == 'j') 
            input[i] = 'i';
    }
    
    char temp[1000];
    int tempIndex = 0, alphabet[26] = {0}, row = 0, col = 0;
    alphabet[9] = -1;  // Exclude 'j'
    
    // Fill 'temp' with the unique characters from the key
    for (int i = 0; i < strlen(input); i++) {
        if (isalpha(input[i]) && alphabet[input[i] - 'A'] == 0) {
            temp[tempIndex++] = input[i];
            alphabet[input[i] - 'A'] = 1;  // Mark letter as used
        }
    }
    
    // Fill the rest of the matrix with the unused letters of the alphabet
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] == 0 && i != 9) {  // Skip 'j'
            temp[tempIndex++] = 'A' + i;
        }
    }
    
    // Populate the 5x5 matrix with the characters in 'temp'
    int index = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = temp[index++];
        }
    }
}

void encryptPair(char char1, char char2) {
    char1=toupper(char1);
    char2=toupper(char2);
    int row1 =-1,col1 =-1,row2 =-1,col2 =-1;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if (matrix[i][j] == char1) {
                row1 = i;
                col1 = j;
             } 
             else if (matrix[i][j] == char2) {
                row2 = i;
                col2 = j; 
            }
        }
    }
    if (row1 == row2) {
        col1 = (col1 + 1) % 5;
        col2 = (col2 + 1) % 5;
    } 
    else if (col1 == col2) {
        row1 = (row1 + 1) % 5;
        row2 = (row2 + 1) % 5; } 
    else {
        int temp = col1;
        col1 = col2;
        col2 = temp;
    }
    cipherText[cipherIndex] =matrix[row1][col1];
    cipherIndex++;
    cipherText[cipherIndex] =matrix[row2][col2];
    cipherIndex++;
}

void processInput(char input[]) {
    int index = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == 'j') input[i] = 'i';
    }
    char char1 = '*', char2 = '*';
    while (index < strlen(input)) {
        if(char1!='*'&&char2!='*') {
            encryptPair(char1, char2);
            char1 = '*';
            char2 = '*';
        } 
        else if (isalpha(input[index])) {
            if (char1 == '*') {
                char1 = input[index];
                index++;
            }
            else {
                if (char1 == input[index]) {
                    char2 = 'x';
                } 
                else {
                    char2 = input[index];
                    index++;
                }
            }
        } 
        else {
            index++; 
        }
    }
    if(index >= strlen(input)) {
        if(char1 != '*' && char2 == '*')
            encryptPair(char1, 'x');
        else
            encryptPair(char1, char2);
    }
}

int main() {
    char plaintext[1000], key[1000];
    printf("Enter the plain text : ");
    scanf("%[^\n]",plaintext);
    printf("Enter the key : ");
    scanf("%s",key);
    createMatrix(key);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ",matrix[i][j]);
        } 
        printf("\n");
    }
    processInput(plaintext);
    printf("%s", cipherText);
    return 0; 
}
