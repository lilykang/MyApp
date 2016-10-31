'''
Pset6 - Mario (less comfortable)
Print out a half-pyramid of height specified by the user
CS50
'''

import cs50

def main():
    h = get_height_int()
    
    # print the pyramid according to user input
    for i in range(h):
        for j in range(h - i - 1):
            print(" ", end="")
        for k in range(i + 1):
            print("#", end="")
        print("#")
            
# define the object that takes user input for height 
def get_height_int(): 
    while True:
        print("Height: ", end="")
        n = cs50.get_int()
        if n >= 0 and n <= 23:
            break
    return n

# implement main
if __name__ == "__main__":
    main()