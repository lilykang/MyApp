#include <stdio.h>
#include <cs50.h>

void water(int n);

int main(void)
{
   
    printf("minutes: \n");
    int n = get_int();
    water(n);
}

void water(int n)
{
    printf("bottles: %i\n", n * 12);
}
