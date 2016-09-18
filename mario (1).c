#include <cs50.h>
#include <stdio.h>

int main(void)
{
   
    printf("height: \n");
    int n = get_int();
    
    while (n > 23 || n < 0)
    {
         n = get_int();
    }
    
    int i = 0;
    int j = 0; 
    
    for (i = 0; i < n; i++)
    {
         for (j = 0, j < i; j++)
         {
             printf("%c %c",' ',"##");
         }
    }
    return 0;
   
}