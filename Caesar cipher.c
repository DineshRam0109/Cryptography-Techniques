#include<stdio.h>
#include<string.h>
#include<ctype.h>

// Function to encrypt the message using Caesar cipher
char* encryption(char msg[], int key) {
    for (int i = 0; msg[i]; i++) {
        char ch = msg[i];

        // Encrypt uppercase characters
        if (isupper(ch)) {
            ch = (ch - 'A' + key) % 26 + 'A';
        }
        // Encrypt lowercase characters
        else if (islower(ch)) {
            ch = (ch - 'a' + key) % 26 + 'a';
        }

        msg[i] = ch; // Assign the encrypted character back to the message
    }
    return msg;
}

// Function to decrypt the message using Caesar cipher
char* decryption(char msg[], int key) {
    for (int i = 0; msg[i]; i++) {
        char ch = msg[i];

        // Decrypt uppercase characters
        if (isupper(ch)) {
            ch = (ch - 'A' - key + 26) % 26 + 'A'; // +26 ensures no negative values
        }
        // Decrypt lowercase characters
        else if (islower(ch)) {
            ch = (ch - 'a' - key + 26) % 26 + 'a'; // +26 ensures no negative values
        }

        msg[i] = ch; // Assign the decrypted character back to the message
    }
    return msg;
}

int main() {
    char msg[10000];
    int key;

    // Input message from user
    printf("Enter the message: ");
    scanf(" %[^\n]s", msg); // Corrected to read the entire string including spaces

    // Input key from user
    printf("Enter the key: ");
    scanf("%d", &key);

    key %= 26; // Adjust key to be within 0-25

    // Encrypt the message
    char *encryptedMessage = encryption(msg, key);
    printf("Encrypted message: %s\n", encryptedMessage);

    // Decrypt the message
    char *decryptedMessage = decryption(encryptedMessage, key);
    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}

