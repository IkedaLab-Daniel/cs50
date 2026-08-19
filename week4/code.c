#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char *s = "Hello!";
    printf("%p\n", s);
    printf("%p\n", &s[0]);
}