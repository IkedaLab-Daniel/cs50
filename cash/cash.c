#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask user input, prevent < 0
    int change_own = 0;
    do
    {
        change_own = get_int("Change owed: ");
    }
    while (change_own < 0);

    // initialize variable. MUST BE WITH " = 0" or else it will
    // start at random value when "coins + 1" !!!
    long coins = 0;

    while (change_own > 0)
    {
        // loops and check each coin values starting from highest to lowest
        if (change_own >= 25)
        {
            coins = coins + 1;
            change_own = change_own - 25;
        }
        else if (change_own >= 10)
        {
            coins = coins + 1;
            change_own = change_own - 10;
        }
        else if (change_own >= 5)
        {
            coins = coins + 1;
            change_own = change_own - 5;
        }
        else if (change_own >= 1)
        {
            coins = coins + 1;
            change_own = change_own - 1;
        }
    }

    // print result (total coins)
    printf("%ld\n", coins);
}
