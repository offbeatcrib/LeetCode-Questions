// 7. Reverse Integer
#include <stdio.h>

int reverse(int x);
int reverse_v2(int x);

int main(void)
{
    int x = 1534236461;

    printf("Reversed: %d\n", reverse(x));
    printf("Reversed v2: %d\n", reverse(x));
}

int reverse_v2(int x) // Second submission after inspiration from other users
{
    long reverse = 0;

    while (x)
    {
        reverse = (reverse * 10) + (x % 10);
        if (reverse < -2147483648 || reverse > 2147483647)
            return 0;
        x /= 10;
    }
    return reverse;
}

int reverse(int x) // First orginal successful submission
{
    int copyx;

    // Negative check 1, and check if the integer is within 32 bits
    if (x < 0)
        copyx = (unsigned)x * -1;
    else
        copyx = x;

    long mod = 10;
    long reverse = 0;
    for (int i = copyx; i > 0; i /= 10)
    {
        reverse = (reverse * 10) + (copyx % mod) / (mod / 10);
        mod *= 10;
    }
    if (reverse > 2147483647)
        return 0;

    // Negative check 2
    if (x < 0)
        return reverse *= -1;
    else
        return reverse;
}