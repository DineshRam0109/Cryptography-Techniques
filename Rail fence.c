#include <stdio.h>
#include<string.h>
int main() {
    char plain_text[1000];
    int r,i=0;
    
    printf("Enter the Plain text:");
    scanf("%[^\n]",plain_text);
    printf("Enter the no.of.rails : ");
    scanf("%d",&r);
    
    int l=strlen(plain_text);
    
    char arr[r][l],encrypted[l],decrypted[l];

    for(int j=0;j<r;j++){
        for(int k=0;k<l;k++){
            arr[j][k]='-';
        }
    }
    
    for(int j=0;j<l;j++){
        arr[i][j]=plain_text[j];
        if((j/(r-1))%2==0)
            i++;
        else
            i--;
    }
    i=0;
    for(int j=0;j<r;j++){
        for(int k=0;k<l;k++){
            if(arr[j][k]!='-'){
                encrypted[i]=arr[j][k];
                i++;
            }
        }
    }
    encrypted[i]='\0';
    printf("Cipher text:%s\n",encrypted); 
    
    int in=0;
    i=0;
    for(int j=0;j<l;j++){
        if(arr[i][j]!='-'){
            decrypted[in++]=arr[i][j];
        }
        if((j/(r-1))%2==0)
            i++;
        else
            i--;
    }
    decrypted[in]='\0';
    printf("Decrypted Text:%s",decrypted);
}

