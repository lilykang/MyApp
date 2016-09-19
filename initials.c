#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string();
    
    // Print the first character
    printf("%c", toupper(name[0]));  
    int i = 0;
    
    // Loop until reaching the end of input
    while (name[i] != '\0')
    {
        // Print out the character after each space
        if (name[i] == ' ')  
        {
            printf("%c", toupper(name[i+1]));
        }
        
        // Move to the next character in the string by increasing i
        i++;  
    }
    printf("\n");
}