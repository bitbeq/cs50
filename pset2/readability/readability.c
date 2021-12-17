#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int letters = 0;
    int words = 1;
    int sentences = 0;
    float grade = 0.0;
    string input = get_string("Text: ");

    // Parse the Input String
    for (int i = 0, len = strlen(input); i < len; i++)
    {
        if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z'))
        {
            letters++;
        }
        else if (input[i] == ' ')
        {
            words++;
        }
        else if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            sentences++;
        }
    }

    // Calculate the Grade
    grade = 0.0588 * (100 * (letters / (float) words)) - 0.296 * (100 * (sentences / (float) words)) - 15.8;

    // Print if the Grade is Between 1 and 16
    if (grade < 16 && grade >= 1)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    // If Grade is 16 or Higher, Print 16+
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    // Else, the Grade is Before Grade 1
    else
    {
        printf("Before Grade 1\n");
    }

}