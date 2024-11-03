#include <stdio.h>
#include <string.h>

char original[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char substitute[] = "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";

char* encryptMessage(char message[]) {
    int i, j;
    for(i = 0; i < strlen(message); i++) {
        if((message[i] >= 'a' && message[i] <= 'z') || (message[i] >= 'A' && message[i] <= 'Z')) {
            for(j = 0; j < strlen(original); j++) {
                if(message[i] == original[j]) {
                    message[i] = substitute[j];
                    break;
                }
            }
        }
    }
    return message;
}

char* decryptMessage(char message[]) {
    int i, j;
    for(i = 0; i < strlen(message); i++) {
        if((message[i] >= 'a' && message[i] <= 'z') || (message[i] >= 'A' && message[i] <= 'Z')) {
            for(j = 0; j < strlen(substitute); j++) {
                if(message[i] == substitute[j]) {
                    message[i] = original[j];
                    break;
                }
            }
        }
    }
    return message;
}

int main() {
    char message[100];
    int choice;

    printf("Enter a message: ");
    scanf("%[^\n]s",message);
    
    char* plain=decryptMessage(message);
    printf("Plain Text:%s",plain);
    
    char* cipher=encryptMessage(message);
    printf("\nCipher Text:%s",cipher);
    
    return 0;
}

