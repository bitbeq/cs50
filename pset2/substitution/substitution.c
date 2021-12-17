#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool validateKey(string key);
void getCipherText(string *cipherText, string plainText, string key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];

        if (validateKey(key) == true)
        {
            string plainText = get_string("plaintext: ");
            string cipherText = malloc(strlen(plainText));
            getCipherText(&cipherText, plainText, key);
            printf("ciphertext: %s\n", cipherText);
        }
        else
        {
            return 1;
        }

    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    return 0;
}

// Validates the key inputed into the program
bool validateKey(char key[])
{
    int length = strlen(key);

    // Create a boolean function to check for repeat alphabetical characters
    // and that the key is legit.
    bool alpha[26] = { false };

    // Check for 26 characters in string, if not return false
    if (length != 26)
    {
        printf("Key must contain 26 characters.");
        return false;
    }

    // Check if the string characters are in the alhpabet
    // Check if each letter is counted for.
    // If either are not true then return false
    for (int i = 0; i < length; i++)
    {
        if (!((key[i] >= 'A' && key[i] <= 'Z') || (key[i] >= 'a' && key[i] <= 'z')))
        {
            printf("Usage: ./substitution key");
            return false;
        }
        else if (alpha[toupper(key[i]) - 65] == true)
        {
            printf("Usage: ./substitution key");
            return false;
        }
        else
        {
            alpha[toupper(key[i]) - 65] = true;
        }
    }

    return true;
}

// Function that gets the cipherText, plainText and key and translates it
void getCipherText(string *cipherText, string plainText, string key)
{
    for (int i = 0, len = strlen(plainText); i < len; i++)
    {
        // Check if the plain text is uppercase
        if (plainText[i] >= 'A' && plainText[i] <= 'Z')
        {
            (*cipherText)[i] = toupper(key[plainText[i] - 65]);
        }

        // Check if the plain text is lowercase
        else if (plainText[i] >= 'a' && plainText[i] <= 'z')
        {
            (*cipherText)[i] = tolower(key[plainText[i] - 97]);
        }

        // Check if the plain text is non-alphabetical, then just pass thru plain to cipher
        else
        {
            (*cipherText)[i] = plainText[i];
        }
    }

}