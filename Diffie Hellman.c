#include <stdio.h>
long long modular_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}
int main() {
    long long Xa, Xb, q, alpha, Ya, Yb, Ka, Kb;
    printf("Enter A's private key: ");
    scanf("%lld", &Xa);
    printf("Enter B's private key: ");
    scanf("%lld", &Xb);
    printf("Enter the prime number (q): ");
    scanf("%lld", &q);
    printf("Enter the Primitive root of q: ");
    scanf("%lld", &alpha);
    Ya = modular_exp(alpha, Xa, q);
    Yb = modular_exp(alpha, Xb, q);
    printf("A's Public Key (Ya): %lld\n", Ya);
    printf("B's Public Key (Yb): %lld\n", Yb);
    Ka = modular_exp(Yb, Xa, q);
    Kb = modular_exp(Ya, Xb, q);
    if (Ka == Kb) {
        printf("Shared Key is: %lld\n", Ka);
    } else {
        printf("Shared Key does not match.\n");
    }
    return 0;
}
