// 13. Roman to Integer **NOT PASSED YET**
#include <stdio.h>
#include <string.h>

int romanToInt(char *s);
int romanToIntV2(char *s);

typedef struct
{
    char numeral;
    int value;
} Roman;

Roman roman[] = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

// ('I', 'V', 'X', 'L', 'C', 'D', 'M')
int main(void)
{
    char *s = "MDCXCV";

    printf("%d\n", romanToIntV2(s));
    printf("%d\n", romanToInt(s));
}

int romanToIntV2(char *s) // work in prog
{
    int tot = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        for (int n = 0; n < 7; n++)
        {
            if (s[i] != roman[n].numeral)
                continue;
            if ((s[i + 1] == roman[n + 1].numeral && s[i + 2] == roman[n + 2].numeral) ||
                (s[i + 1] == roman[n + 1].numeral && s[i + 2] != roman[n + 2].numeral))
            {
                tot += roman[n + 1].value - roman[n].value;
                i++;
                break;
            }
            else if (s[i + 1] == roman[n + 2].numeral)
            {
                tot += roman[n + 2].value - roman[n].value;
                i++;
                break;
            }
            tot += roman[n].value;
            break;
        }
    }
    return tot;
}

int romanToInt(char *s) // Version 1 first suc sub
{
    int total = 0;
    // Iterate throught string
    for (int i = 0; i < strlen(s); i++)
    {
        printf("tot check: %d\n", total);
        switch (s[i]) // Check if there is a subtractive value ahead of the current index
        {
        case 'I':
            if (s[i + 1] == 'V')
            {
                total += 4;
                i++;
            }
            else if (s[i + 1] == 'X')
            {
                total += 9;
                i++;
            }
            else
                total += 1;
            break;
        case 'V':
            total += 5;
            break;
        case 'X':
            if (s[i + 1] == 'L')
            {
                total += 40;
                i++;
            }
            else if (s[i + 1] == 'C')
            {
                total += 90;
                i++;
            }
            else
                total += 10;
            break;
        case 'L':
            total += 50;
            break;
        case 'C':
            if (s[i + 1] == 'D')
            {
                total += 400;
                i++;
            }
            else if (s[i + 1] == 'M')
            {
                total += 900;
                i++;
            }
            else
                total += 100;
            break;
        case 'D':
            total += 500;
            break;
        case 'M':
            total += 1000;
            break;
        default:
            break;
        }
    }
    printf("tot check: %d\n", total);

    return total;
}

// int romanToIntV2(char *s)
// {
//     int tot = 0;
//     int first;
//     int sec;
//     for ( int i = 0; i < strlen(s); i++)
//     {
//         printf("tot check: %d\n", tot);
//         for (int n = 0; n < 7; n++)
//         {
//             if (s[i] == roman[n].numeral)
//                 first = n;
//             if (s[i+1] == roman[n+1].numeral && s[i+1] == roman[n+2].numeral)
//                 sec = n;
//         }
//         if(roman[first].value < roman[sec].value)
//         {
//             tot += roman[sec].value - roman[first].value;
//             i++;
//         } else
//             tot += roman[first].value;
//     }
//     printf("tot check: %d\n", tot);
//     return tot;
// }