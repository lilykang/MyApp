#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    // Checking number of command-line arguments
    if (argc != 2)
    {
        printf("Please enter one command-line argument\n");
        return 1;
    }
     
    // Checking whether argument contains only alphebets
   for (int j = 0, n = strlen(argv[1]); j < n; j++)
    {
       if (isalpha(argv[1][j]) == false)
       {
        printf("Enter only alphabetical characters\n");
        return 1;
       }
    }
    
    string key = argv[1];
    int key_ai[strlen(key)];
    
    printf("plaintext: ");
    string plaintext = get_string();
    
    if (plaintext != NULL)
    {
        // Covert the key into an array of alphabetical index numbers 
        for (int j = 0, n = strlen(key); j < n; j++)
        {
            if (isupper (key[j]) != 0)
            {
                key_ai[j] = (int)key[j] - (int)65;
            }
         
            if (islower (key[j]) != 0) 
            {
                key_ai[j] = (int)key[j] - (int)97;
            }
        }
        
        int i = 0, k = 0;
        printf("ciphertext: ");
        
        //loop through each character to encrypt it
        
        while (plaintext[i] != '\0')
        {
            int ai = 0, new_ascii = 0;
            
            // check to see if character is an alphabet
            if (isalpha(plaintext[i]) != 0)
            
            {
                if (isupper(plaintext[i]) != 0)
                {
                    ai = (int)plaintext[i]- (int)65;  // alphabetical index number for the letter
                    new_ascii = (ai + key_ai[k % strlen(key)]) % (int)26 + (int)65; // the new ascii number after encryption
                    printf("%c", (char)new_ascii);
                    i++;
                    k++;
                }
            
                else if (islower(plaintext[i]) != 0)
                {
                    ai = (int)plaintext[i]- (int)97;  // alphabetical index number for the letter
                    new_ascii = (ai + key_ai[k % strlen(key)]) % (int)26 + (int)97; // the new ascii number after encryption
                    printf("%c", (char)new_ascii);
                    i++;
                    k++;
                }
            }
            
            // if the character is not an alphabet, no encrytion is created
            else
            {
                printf("%c",plaintext[i]);
                i++;
            }
            
        }

        printf("\n");
    }
    return 0;
}