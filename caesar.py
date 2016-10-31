'''
Pset6 - Caesar (less comfortable)
Encrypt message using Caesar's cipher  
CS50
'''

import cs50
import sys

# ensure proper usage
if len(sys.argv) != 2:
    print("Usage: python caesar.py k")
    exit(1)

# convert the command-line argument into an integer
k = int(sys.argv[1])

# prompt user to input plaintext
print("Plaintext: ", end="")
plaintext = cs50.get_string()


# check to see if input value is null
if plaintext != None: 

    # iterate through each character in the user's input
    for i in range(len(plaintext)):
            
        # encrypt uppercase alphabetical characters
        if plaintext[i].isupper():
            num = ord(plaintext[i]) 
            i = num - 65
            ai = (i + k) % 26
            cipher = ai + 65
            print(chr(cipher), end="")
            
        # encrypt lowercase alphabetical characters
        elif plaintext[i].islower():
            num = ord(plaintext[i]) 
            i = num - 97
            ai = (i + k) % 26
            cipher = ai + 97
            print(chr(cipher), end="")
         
        # skip non-alphabetical characters   
        else: 
            print(plaintext[i], end="")
         
    # add a new line when finishing encrypting the entire user input
    print("")
    exit(0)


