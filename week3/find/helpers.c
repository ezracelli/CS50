/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else returns false.
 */
 // usage search(needle, haystack, size)
bool search(int value, int values[], int n)
{
    // declare ranges
    int middle;
    int right = n - 1;
    int left = 0;
    
    // execute if list if not of length zero
    while (right >= left)
    {
        // middle is average
        middle = (right + left) / 2;
        
        // value was found
        if (value == values[middle])
        {
            return true;
        }
        
        // if value wasn't found, change middle
        if (value < values[middle])
        {
            right = middle - 1;
        }
        else if (value > values[middle])
        {
            left = middle + 1;
        }
    }
    
    
    // value was not found
    return false;
}

/**
 * Sorts array of n values.
 */
 // usage sort(values, size)
void sort(int values[], int n)
{
    // declare buffer
    int buffer;
    
    // declare changed switch
    int changed;
    
    // execute loop once, then redo until it isn't changed
    do
    {
        // reset changed value to false
        changed = 0;
        
        // execute for each value in values
        for (int i = 0; i < n - 1; i++)
        {
            // execute if two values are not sorted
            if (values[i] > values[i + 1])
            {
                // change values
                buffer = values[i];
                values[i] = values[i + 1];
                values[i + 1] = buffer;
                
                // set changed to true
                changed = 1;
            }
        }
    } while (changed != 0);
    
    return;
}
