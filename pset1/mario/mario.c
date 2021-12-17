#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Prompt user to input height of mario stairs
    // Must be between 1 and 8.
    do
    {
        height = get_int("Height: ");
    }
    while (!(height >= 1 && height <= 8));

    // Print the Mario Stairs
    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j <= (height + 2) + i; j++)
        {
            if (((j < height - i || j > height + i + 1) || j == height || j == height + 1) && j < (height + 1) + i)
            {
                printf(" ");
            }
            else if (j != height + 2)
            {
                printf("#");
            }
        }
        printf("\n");
    }

}