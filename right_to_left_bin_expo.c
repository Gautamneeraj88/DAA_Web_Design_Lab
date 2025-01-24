#include <stdio.h>

long long binExpoRTL(long long a, long long b){
    long long result = 1;

    while(b > 0) {
        if (b % 2 == 1) {
            result *= a;
        }
        a *= a;
        b /= 2;
    }
    return result;
}

int main ()
{
    long long a, b;
    printf("Enter the base (a) and exponent (b): ");
    scanf("%lld %lld", &a, &b);
    long long result = binExpoRTL(a, b);
    printf("Result of %lld^%lld = %lld\n", a, b, result);
}
