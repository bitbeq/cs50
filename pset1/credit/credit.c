#include <cs50.h>
#include <stdio.h>

int countDigitsInLong(long num)
{
    int digits = 1;

    while (num > 9)
    {
        digits++;
        num /= 10;
    }
    return digits;
}

int main(void)
{
    long creditCard = get_long("Number: ");
    int digits = countDigitsInLong(creditCard);

    // even first
    // odd second

    int j = 10;

    for (int i = digits; i >= 1; i--)
    {
        if (i % 2)
        {
            printf("%li\n", ( creditCard / j) % 10);
        }
        j *= 10;
    }

    // printf("%i\n", digits);
    // printf("%li\n", creditCard);

    // printf("%li\n", creditCard % 10);
    // printf("%li\n", (creditCard / 10) % 10);
    // printf("%li\n", (creditCard / 10000) % 10);
    // printf("%li\n", ((creditCard / 10) / 10) % 10);

}