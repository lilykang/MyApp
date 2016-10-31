'''
Pset6 - Greedy (less comfortable)
Calculate the minumum number of coins to give user change 
CS50
'''
import cs50
import math

def main():
    # get the total amount of change required from user
    amount = get_amount_float()
    
    # convert the change required to cents
    cents = round(amount * 100)
    
    # initialize the number of coins needed
    n = 0
    
    # increase the number of coins needed by the the maximum number of quarters 
    n += cents // 25
    
    # calculate the remaining amount of change 
    cents = cents % 25
    
    n += cents // 10
    cents = cents % 10 
    
    n += cents // 5
    cents = cents % 5
    
    n += cents / 1 
    
    print(n)
    

# define the class that asks for user input 
def get_amount_float(): 
    while True:
        print("Amount owed: ", end="")
        n = cs50.get_float()
        if n >= 0:
            break
    return n

# implement main 
if __name__ == "__main__":
    main()