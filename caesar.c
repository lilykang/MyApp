#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Checking number of command-line arguments
    if (argc != 2)
    {
        printf("Please enter one command-line argument\n");
        return 1; 
    }
    
    // converting command-line argument into integer k
    int k = atoi(argv[1]);
    
    // prompt the user to enter plaintext 
    printf("plaintext: ");
    string plaintext = get_string();
    printf("ciphertext: ");
   
    if (plaintext != NULL)
    {
        // Loop through each character of the user's input
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            int ai = 0, j = 0;
            
            // Shifting letters by k places for uppercase letters
            
            if (isupper(plaintext[i]) != 0)
            {
                ai = (int)plaintext[i]- (int)65;  // alphabetical index number for the letter
                j = (ai + k) % (int)26 + (int)65;
                printf("%c", (char)j);
            }
            
            // Shifting letters by k places for lowercase letters
            
            else if (islower(plaintext[i]) != 0)
            {
                ai = (int)plaintext[i]- (int)97;  // alphabetical index number for the letter
                j = (ai + k) % (int)26 + (int)97;
                printf("%c", (char)j);
            }
            
            // When the input is not a letter, no encryption is made
            else
            {
                printf("%c", plaintext[i]);
            }
                
        }
        // starting a new line
        printf("\n");
    }
    return 0;
}