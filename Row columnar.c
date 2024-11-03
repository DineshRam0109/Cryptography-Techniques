#include <stdio.h>
#include <string.h>

// Encryption function
void Encryption(int no_rows, int len_key, int len_msg, char msg[], int col_val[], char cipher[])
{
    int x = 0;
    char enc_mat[no_rows + 1][len_key];

    // Creating the matrix
    for (int i = 0; i < no_rows + 1; i++) {
        for (int j = 0; j < len_key; j++) {
            // Initializes the positions with '_' after the end of the message
            if (x >= len_msg) {
                enc_mat[i][j] = '_';
            } else {
                enc_mat[i][j] = msg[x];
            }
            x++;
        }
    }

    int t = 1;
    int cipher_pos = 0;

    // Finding the cipher text according to the value of col_val matrix
    while (t <= len_key) {
        for (int i = 0; i < len_key; i++) {
            int k = col_val[i];
            if (k == t) {
                for (int j = 0; j < no_rows + 1; j++) {
                    cipher[cipher_pos++] = enc_mat[j][i];
                }
                t++;
            }
        }
    }
    cipher[cipher_pos] = '\0';  // Null-terminate the cipher string
}

// Decryption function
void Decryption(int no_rows, int len_key, char cipher[], int col_val[], char message[])
{
    char dec_mat[no_rows + 1][len_key];
    int x = 0, t = 1;

    // Rearrange the matrix according to the col_val
    while (t <= len_key) {
        for (int i = 0; i < len_key; i++) {
            int k = col_val[i];
            if (k == t) {
                for (int j = 0; j < no_rows + 1; j++) {
                    dec_mat[j][i] = cipher[x++];
                }
                t++;
            }
        }
    }

    int message_pos = 0;

    for (int i = 0; i < no_rows + 1; i++) {
        for (int j = 0; j < len_key; j++) {
            // Replacing '_' with space
            if (dec_mat[i][j] == '_') {
                dec_mat[i][j] = ' ';
            }
            message[message_pos++] = dec_mat[i][j];
        }
    }
    message[message_pos] = '\0';  // Null-terminate the message string
}

int main()
{
    char msg[100], key[100];

    // Read message from user
    printf("Enter the message: ");
    scanf(" %[^\n]s", msg);  // Reading message with spaces

    // Read key from user
    printf("Enter the key: ");
    scanf("%s", key);

    int len_key = strlen(key);
    int len_msg = strlen(msg);

    int val = 1, count = 0, ind;

    int col_val[len_key];
    // Initializing col_val matrix with 0
    memset(col_val, 0, sizeof(col_val));

    // Numbering the key alphabets according to their ASCII value
    while (count < len_key) {
        int min = 999;
        for (int i = 0; i < len_key; i++) {
            if ((min > (int)key[i]) && (col_val[i] == 0)) {
                min = (int)key[i];
                ind = i;
            }
        }
        col_val[ind] = val;
        count++;
        val++;
    }

    int no_rows = len_msg / len_key;
    
    // Encrypted text
    char cipher_text[100];
    Encryption(no_rows, len_key, len_msg, msg, col_val, cipher_text);
    printf("Encrypted Message: %s\n", cipher_text);
    
    // Decrypted text
    char original_msg[100];
    Decryption(no_rows, len_key, cipher_text, col_val, original_msg);
    printf("Decrypted Message: %s\n", original_msg);

    return 0;
}

