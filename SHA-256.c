#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
void calculateSHA256(const char *input, unsigned char output[SHA256_DIGEST_LENGTH]) {
 SHA256((unsigned char*)input, strlen(input), output);
}
void printHash(unsigned char hash[SHA256_DIGEST_LENGTH]) {
 for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
 printf("%02x", hash[i]);
 }
 printf("\n");
}
int main() {
 const char *text = "Hello, world!";
 unsigned char hash[SHA256_DIGEST_LENGTH];
 calculateSHA256(text, hash);
 
 printf("Input: %s\n", text);
 printf("SHA-256 Hash: ");
 printHash(hash);
 return 0;
}
