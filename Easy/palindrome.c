#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x);

int main(void)
{
    int x = 1331;
    // Find if the integer is a palindrome
    if (isPalindrome(x) == true)
    {
        printf("%d reads as %d from left to right and from right to left.\n", x, x);
    } else
    {
        printf("False\n");
    }   
}

bool isPalindrome(int x)
{
    // Reverse the integer input
    long int mod = 10;
    long int palx = 0;
    for (int i = x; i > 0; i /= 10)
    {
        palx = (palx * 10) + (x % mod) / (mod / 10);
        mod *= 10;
    }
    // Check if the reversed integer is == to the orginal
    if (palx == x)
        return true;
    return false;
}  