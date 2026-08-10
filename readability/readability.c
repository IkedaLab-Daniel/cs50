#include <cs50.h>
#include <ctype.h> // isalpha
#include <math.h> //round
#include <stdio.h> 
#include <string.h> // strlen, i ain't redoing char counter brodar

void calculate(int total_characters, int total_words, int total_sentences);

int main(void)
{
    string user_input = get_string("Text: ");

    // count total character alphabet
    int total_characters = 0;
    for (int i = 0, n = strlen(user_input); i < n; i++)
    {
        if (isalpha(user_input[i]))
        {
            total_characters++;
        }
    }

    printf("Total chracters: %i\n", total_characters);

    // count total words
    int total_words = 1; // start at 1 for the last word
    for (int i = 0, n = strlen(user_input); i < n; i++)
    {
        if (user_input[i] == ' ')
        {
            total_words++;
        }
    }
    printf("Total words: %i\n", total_words);

    // count total sentences
    int total_sentences = 0;
    for (int i = 0, n = strlen(user_input); i < n; i++)
    {
        if (user_input[i] == '.' || user_input[i] == '!' || user_input[i] == '?')
        {
            total_sentences++;
        }
    }
    printf("Total sentences: %i\n", total_sentences);

    calculate(total_characters, total_words, total_sentences);
}

void calculate(int total_characters, int total_words, int total_sentences)
{
    // index = 0.0588 * L - 0.296 * S - 15.8
    // calculate L anad S
    float L = ((float) total_characters / total_words) * 100;
    float S = ((float) total_sentences / total_words) * 100;

    // solve for index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}