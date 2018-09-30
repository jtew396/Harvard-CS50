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

 //needle, haystack, size


bool search(int value, int values[], int n)
{
    if(n < 0)
    {
        return false;
    }


    /*

        I searched the internet and found this website to help with my binary search
        http://www.programmingsimplified.com/c/source-code/c-program-binary-search

        I mirror this in my code below declaring first, last, and mid as integers
        then using them in my while loop in order to complete my binary search.

    */


    int first, last, mid;

    first = 0;
    last = n - 1;
    mid = (first + last) / 2;

    while (first <= last)
        {

            if(values[mid] == value)
            {
                return true;
            }
            else if(values[mid] < value)
            {
                first = mid + 1;
            }
            else if(values[mid] > value)
            {
                last = mid - 1;
            }

            mid = (first + last) / 2;

        }
    return false;
}

/**
 * Sorts array of n values.
 */

 //haystack, size

void sort(int values[], int n)
{
    int min, i, a;

    for (i = 0; i < n - 2; i++)
    {
        //make the first index the minimum
        min = i;

        //iterate to check for the minimum
        for (a = i + 1; a <= n - 1; a++)
        {
            if(values[a] < values[min])
            {
                min = a;
            }
        }

        if(min != i)
        {

            int swap = values[min];
            values[min] = values[i];
            values[i] = swap;

        }



    }

    return;
}
