#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // check if user input argument in execution ./caesar
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // ensure every char in key is a digit
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // convert argument into integer
    int k = atoi(argv[1]);

    // get plaintext to cipher
    string plaintext = get_string("plaintext:  ");

    // cipher logic: transform plaintext in place
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        // check if uppercase letter
        if (isupper(c))
        {
            plaintext[i] = ((c - 'A' + k) % 26) + 'A';
        }
        // check if lowercase letter
        else if (islower(c))
        {
            plaintext[i] = ((c - 'a' + k) % 26) + 'a';
        }
    }

    printf("ciphertext: %s\n", plaintext);
}