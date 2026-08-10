#include <cs50.h>
#include <stdio.h>

// init prototypes
int get_size(string str_input);
int get_score(char alphabet);
int serialize_char(char alphabet);

int main(void)
{
    // user input
    string player_one = get_string("Player 1: ");
    string player_two = get_string("Player 2: ");

    // init scores
    int player_one_score = 0;
    int player_two_score = 0;

    // calculate score player 1
    for (int i = 0; i < get_size(player_one); i++)
    {
        // serialize value -> turn lowercase input and into their numerical upper case
        char cleaned_input = serialize_char(player_one[i]);
        if (cleaned_input != '0')
        {
            player_one_score += get_score(cleaned_input);
        }
    }

    // calculate score player 2
    for (int i = 0; i < get_size(player_two); i++)
    {
        // serialize value -> turn lowercase input and into their numerical upper case
        char cleaned_input = serialize_char(player_two[i]);
        if (cleaned_input != '0')
        {
            player_two_score += get_score(cleaned_input);
        }
    }

    // result
    if (player_one_score > player_two_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player_one_score < player_two_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int get_score(char alphabet)
{

    // check for 1 point characters
    if (alphabet == 'A' || alphabet == 'E' || alphabet == 'I' || alphabet == 'L' ||
        alphabet == 'N' || alphabet == 'O' || alphabet == 'R' || alphabet == 'S' ||
        alphabet == 'T' || alphabet == 'U')
    {
        return 1;
    }
    // check for 2 points characters
    else if (alphabet == 'D' || alphabet == 'G' || alphabet == 'A')
    {
        return 2;
    }
    // check for 3 points characters
    else if (alphabet == 'B' || alphabet == 'C' || alphabet == 'M' || alphabet == 'P')
    {
        return 3;
    }
    // check for 4 points characters
    else if (alphabet == 'F' || alphabet == 'H' || alphabet == 'V' || alphabet == 'W' ||
             alphabet == 'Y')
    {
        return 4;
    }
    // check for 5 points characters
    else if (alphabet == 'K')
    {
        return 5;
    }
    // check for 8 points characters
    else if (alphabet == 'J' || alphabet == 'X')
    {
        return 8;
    }
    // check for 10 points characters
    else
    {
        return 10;
    }
}

int get_size(string str_input)
{
    // initialize variables
    int count = 0;
    int i = 0;

    // begin calculate size of the string by treating it as an array
    while (true)
    {
        if (str_input[i] != 0)
        {
            count = count + 1;
            i = i + 1;
        }
        else
        {
            break;
        }
    }

    return count;
}

int serialize_char(char alphabet)
{
    if ((int) alphabet >= 97 && (int) alphabet <= 122)
    {
        return (int) alphabet - 32;
    }
    // if the character is not an alphabet (e.g. !, ?, $), return 0, and it is handled in the main
    // funtion (if = 0 -> do nothing)
    else if ((int) alphabet < 65 || (int) alphabet > 122)
    {
        return 48;
    }
    else
    {
        return alphabet;
    }
}
