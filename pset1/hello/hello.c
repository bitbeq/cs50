#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Grabs user input for their first name and outputs a hello message.
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}