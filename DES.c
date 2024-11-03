#include <stdio.h>
void makeInitial(int *initial,int PC1[],int key[]){
    for(int j=0;j<56;j++){
        initial[j]=key[PC1[j]-1];
        printf("%d",initial[j]);
    }
    printf("\n");
}
void lcs(int *initial,int s){
    for(int k=0;k<s;k++){
        int f=initial[0];
        for(int j=0;j<27;j++){
            initial[j]=initial[j+1];
        }
        initial[27]=f;
        f=initial[28];
        for(int j=28;j<55;j++){
            initial[j]=initial[j+1];
        }
        initial[55]=f;
    }
}
void permutate(int initial[],int PC2[]){
    int skey[48];
    for(int j=0;j<48;j++){
        skey[j]=initial[PC2[j]-1];
        printf("%d",skey[j]);
    }
}

int main() {
    int key[64] 
={1,0,1,0,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,1,1,1,0,0,1,1,0,1,1,0,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,
0,1,0,0,1,1};
    int initial[56];
    int PC1[56] = { 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 
52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4 
};
    int PC2[48] = { 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 
37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };
    int shifts[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    printf("Initial Permutation: ");
    makeInitial(initial,PC1,key);
    for(int j=0;j<16;j++){
        lcs(initial,shifts[j]);
        printf("Subkey Generated %d: ",j+1);
        permutate(initial,PC2);
        printf("\n");
    }
    return 0;
}

