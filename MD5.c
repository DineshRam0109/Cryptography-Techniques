#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>
void calculateMD5(const char *input, unsigned char output[MD5_DIGEST_LENGTH]) {
 MD5((unsigned char*)input, strlen(input), output);
}
void printHash(unsigned char hash[MD5_DIGEST_LENGTH]) {
 for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
 printf("%02x", hash[i]);
 }
 printf("\n");
}
int main() {
 const char *text = "Hello, world!"; 
 unsigned char hash[MD5_DIGEST_LENGTH];
 calculateMD5(text, hash);
 
 printf("Input: %s\n", text);
 printf("MD5 Hash: ");
 printHash(hash);
 return 0;
}


