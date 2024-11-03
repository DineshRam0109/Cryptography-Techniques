#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<time.h>
#define MOD 26
int det;
int determinant(int K[2][2]) {
    return K[0][0] * K[1][1] - K[0][1] * K[1][0];
}
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
         if ((a * x) % m == 1) {
            return x;
        }
    }
    return 1;
}
void inverseKey(int K[2][2], int invK[2][2]) {
    int det = determinant(K);
    int detInv = modInverse(det, MOD);
 
    invK[0][0] = K[1][1] * detInv % MOD;
    invK[1][1] = K[0][0] * detInv % MOD;
    invK[0][1] = -K[0][1] * detInv % MOD;
    invK[1][0] = -K[1][0] * detInv % MOD;
 
    if (invK[0][0] < 0) invK[0][0] += MOD;
    if (invK[1][1] < 0) invK[1][1] += MOD;
    if (invK[0][1] < 0) invK[0][1] += MOD;
    if (invK[1][0] < 0) invK[1][0] += MOD;
}
void encrypt(char plaintext[], int K[2][2], char ciphertext[]) {
    int len = strlen(plaintext);
    int P[len], C[len];
    for (int i = 0; i < len; i++) {
        if (isupper(plaintext[i])) 
            P[i] = plaintext[i] - 'A';
         else if (islower(plaintext[i])) 
            P[i] = plaintext[i] - 'a';
        else 
            P[i] = plaintext[i];
    }
    for (int i = 0; i < len; i += 2) {
        if (isalpha(plaintext[i]) && isalpha(plaintext[i+1])) {
            C[i] = (K[0][0] * P[i] + K[0][1] * P[i+1]) % MOD;
            C[i+1] = (K[1][0] * P[i] + K[1][1] * P[i+1]) % MOD;
        } 
        else {
            C[i] = P[i];
            if (i + 1 < len) {
                C[i+1] = P[i+1];
            }
        }
    }
    for (int i = 0; i < len; i++) {
        if (isupper(plaintext[i])) 
            ciphertext[i] = C[i] + 'A';
        else if (islower(plaintext[i])) 
            ciphertext[i] = C[i] + 'a';
        else
            ciphertext[i] = plaintext[i];
    }
    ciphertext[len] = '\0';
}
void decrypt(char ciphertext[], int K[2][2], char plaintext[]) {
    int len = strlen(ciphertext);
    int C[len], P[len];
    int invK[2][2];
    inverseKey(K, invK);
    for (int i = 0; i < len; i++) {
        if (isupper(ciphertext[i])) 
            C[i] = ciphertext[i] - 'A';
        else if (islower(ciphertext[i])) 
            C[i] = ciphertext[i] - 'a';
        else
            C[i] = ciphertext[i];
    }
    for (int i = 0; i < len; i += 2) {
        if (isalpha(ciphertext[i]) && isalpha(ciphertext[i+1])) {
            P[i] = (invK[0][0] * C[i] + invK[0][1] * C[i+1]) % MOD;
            P[i+1] = (invK[1][0] * C[i] + invK[1][1] * C[i+1]) % MOD;
        } 
        else {
            P[i] = C[i];
            if (i + 1 < len) {
                P[i+1] = C[i+1];
            }
        }
    }
    for (int i = 0; i < len; i++) {
        if (isupper(ciphertext[i])) 
            plaintext[i] = P[i] + 'A';
        else if (islower(ciphertext[i]))
            plaintext[i] = P[i] + 'a';
        else 
            plaintext[i] = ciphertext[i];
    }
    plaintext[len] = '\0';
}

int func(){
    if(determinant == 0)
        return 0;
    int i = 0;
    while(i < 1000){
        if(((i * det) % 26) == 1)
            return 1;
        i++;
    }
    return 0;
}
int main() {
    //int K[2][2] = {{3, 3}, {2, 5}};
    int K[2][2];
    char plaintext[100];
    char ciphertext[100];
    char decryptedtext[100];

    printf("Enter the plaintext: ");
    scanf("%[^\n]",plaintext);
    int len = strlen(plaintext);
    if (len % 2 != 0) {
        plaintext[len] = 'X';
        plaintext[len + 1] = '\0';
    }
    
    srand(time(0));
    while(1){
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                K[i][j] = rand() % 26;
            }
        }
        det = K[0][0] *K[1][1] - K[0][1] * K[1][0];
        if(func() == 1)
            break;
    }
    
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%d ",K[i][j]);
        }
        printf("\n");
    }
    encrypt(plaintext, K, ciphertext);
    decrypt(ciphertext, K, decryptedtext);
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted text: %s\n", decryptedtext);
    return 0;
}
