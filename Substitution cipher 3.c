#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char msg[100],cipher[100],decrypt[100];

void encryption(char p[],char key[]){
   for(int i=0;i<strlen(p);i++){
    if(isalpha(p[i])){
       int x=p[i]-'A';
       cipher[i]=key[x];
       }
    else{
        cipher[i]=' ';
    }
   }
}
int ind=0;
void decryption(char ci[],char key[]){
    for(int i=0;i<strlen(ci);i++){
        if(isalpha(ci[i])){
            for(int j=0;j<strlen(key);j++){
                if(key[j]==ci[i]){
                decrypt[ind++]='A'+j;
                break;}

            }}
       else{
            decrypt[ind++]=' ';
        }

}
}
int main(){
char k[100];
scanf("%[^\n]",msg);
scanf("\n%[^\n]",k);
encryption(msg,k);
printf("cipher text: ");
printf("%s\n",cipher);
decryption(cipher,k);
printf("Original :");
printf("%s",decrypt);
}
