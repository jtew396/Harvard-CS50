//Jon Thomas E. Williams
//water.c script

#include <stdio.h>
#include <cs50.h> //included the cs50 library to use get_int

int n; //declaring n as an integer

int main(void)
{
    do
    {
        printf("Minutes in the shower: ");
        n = get_int(); //gather input for minutes
    }
    while (n < 0);
    printf("Minutes: %i\n", n); //display the amount of minutes with input n
    printf("Bottles: %i\n", n * 12); //display the amount of bottles multiplying input n by 12
}