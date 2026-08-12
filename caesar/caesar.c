#include <cs50.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Missing cli argument!\n");
        return 1;
    }
    printf("Number: %s\n", argv[1]);
    return 0;
}