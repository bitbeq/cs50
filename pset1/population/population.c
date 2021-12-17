#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int startSize;
    int endSize;

    int result = 0;

    // Prompt the user on what the start size of the population should be.
    // The input must not be less than 9
    do
    {
        startSize = get_int("Start size: ");
    }
    while (!(startSize >= 9));

    // Prompt the user on what the end size of the population should be.
    // End size must be equal to or bigger than startSize.
    do
    {
        endSize = get_int("End size: ");
    }
    while (!(endSize >= startSize));

    // Calculates the year that the llamas will reach endSize.
    while (startSize < endSize)
    {
        startSize += ((startSize / 3) - (startSize / 4));
        result++;
    }

    // Output result
    printf("Years: %i\n", result);
}