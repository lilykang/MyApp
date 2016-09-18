#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float change;
    
    do
    {
        printf("enter the amount owed to you: ");
        change = get_float();
    }
    while (change <= 0);
    
    int x;
    
    x = change * 100;
    
    int quarter = 0;

    while (x >= 25)
    {
       quarter = quarter + 1;
       x = x - 25;
    }

    int dime = 0;     //number of dimes to start off
    int y = x % 25;   //remaining balance in cents
    
    
    while (y >= 10)
    {
        dime = dime + 1;   //increase number of dimes by 1  
        y = y - 10;         //decrease the total amount owed by 10 cents 
    }
    
    int nickel = 0;
    int z = y % 10;
    
    while (z >=5)
    {
        nickel = nickel +1; 
        z = z - 5;
    }
    
    int penny = 0;
    int p = z % 5;
    
    while (p >=1)
    {
        penny = penny +1; 
        p = p - 1;
    }
    
    printf("%i\n", quarter + dime + nickel + penny);
    
}