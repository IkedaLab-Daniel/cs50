#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // ask user for height, repeat if less than 1
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    // start loop, repeat 1 less time of given height (because last line is printed in another loop
    // in line 33)
    for (int i = 1; i < height; i++)
    {
        // pring space
        for (int j = 1; j < height - i + 1; j++)
        {
            printf(" ");
        }
        // print #
        for (int k = 1; k < i + 1; k++)
        {
            printf("#");
        }
        // new line per row
        printf("\n");
    }

    // im not sure if this is the best solution, but the last row is printed here, just print "#"
    // height times
    for (int i = 0; i < height; i++)
    {
        printf("#");
    }

    printf("\n");
}
