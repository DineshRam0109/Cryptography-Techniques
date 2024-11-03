#include <stdio.h>
#include <string.h>
#include<ctype.h>

char* encryption(char msg[]){
    for(int i=0;msg[i];i++){
        char ch=toupper(msg[i]);
        if(ch=='Z')msg[i]='A';
        else msg[i]=ch+1;
    }
    return msg;
}

char* decryption(char msg[]){
    for(int i=0;msg[i];i++){
        char ch=tolower(msg[i]);
        if(ch=='a')msg[i]='Z';
        else msg[i]=ch-1;
    }
    return msg;
}

int main() {
    char message[100]; 

    printf("Enter the encrypted message: ");
    scanf("%[^\n]s",message); 
    
    char* decryptmsg=decryption(message);
    printf("Decrypted Message: %s\n", decryptmsg);
    
    char* encryptmsg=encryption(message);
    printf("Encrypted Message: %s\n", encryptmsg);
    
    return 0;
}

