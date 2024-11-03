#include<stdio.h>
#include<string.h>
#include<ctype.h>
void encrypt(char text[],char key[],char result[]){
    int textLength=strlen(text);
    int keyLength=strlen(key);
    int i,j;
    for(i=0,j=0;i<textLength;i++,j++){
        if (j==keyLength){
            j = 0;
        }
        if(isalpha(text[i])){
            if(isupper(text[i])){
                result[i]=((text[i]-'A')+(toupper(key[j])-'A'))%26+'A';}
            else{
                result[i]=((text[i]-'a')+(tolower(key[j])-'a'))%26+'a'; }}

        else{
            result[i]=text[i];}
    }
    result[textLength] = '\0';
}
void decrypt(char text[],char key[],char result[]){
    int textLength=strlen(text);
    int keyLength=strlen(key);
    int i, j;
    for (i=0,j=0;i<textLength;i++,j++){
        if(j==keyLength){
            j = 0;
        }
        if(isalpha(text[i])){
            if(isupper(text[i])){
                result[i]=((text[i]-'A')-(toupper(key[j])-'A')+26)%26+'A';}
            else{
                result[i]=((text[i]-'a')-(tolower(key[j])-'a')+26)%26+'a';}}
        else{
            result[i]=text[i];}
    }
    result[textLength] = '\0';
}
int main() {
    char text[100]; char key[100];
    char encryptedText[100]; char decryptedText[100];
    printf("Enter text to encrypt: ");
    scanf("\n%[^\n]",text);
    printf("Enter key: ");
    scanf("\n%[^\n]",key);
    encrypt(text, key, encryptedText);
    printf("Encrypted Text: %s\n", encryptedText);
    decrypt(encryptedText, key, decryptedText);
    printf("Decrypted Text: %s\n", decryptedText); return 0;
}
