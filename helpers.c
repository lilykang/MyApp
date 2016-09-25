/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int first = 0, last = n;
    
    // Binary search for the needle in the provided haystack
    while (last - first >= 0)
    {
        if (values[(first + last)/2] == value)
        {
            return true;
        }
            
        else if (values[(first + last)/2] > value)
        {
            last = (first + last)/2 - 1;
        }
        
        else if (values[(first + last)/2] < value)
        {
            first = (first + last)/2 + 1;
        }
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int swap;
    
    // bubble sort to arrange the list of numbers in ascending order 
    for (int i = 0; i < n-1; i++)
    {
        for (int c = 0; c < n-i-1; c++)
        {
            if (values[c] > values[c+1])
            {
                swap = values[c];
                values[c] = values[c+1];
                values[c+1] = swap;
            }
        }
    }
    
    return;
}
