//JT Williams
//greedy.c program

#include <stdio.h>
#include <cs50.h>
#include <math.h>



int main(void)
{
    float change_dollars = 0;
    int change_cents, count = 0;


    do
    {
        printf("Sup dude, how much change is owed?\n");     //prompt the user for the change input
        change_dollars = get_float(); //gather the input as a float
    }
    while (change_dollars < 0); //validate for a positive input

    change_dollars = change_dollars * 100; //multiply the float to convert into cents
    change_cents = (int) round(change_dollars); //store the rounded float into change_cents as an integer


    while (change_cents >= 25) //check for the amount of a quarter
    {
        count++; //add one coin to the counter
        change_cents = change_cents - 25; //subtract the quarter from the total
    }
    while (change_cents >= 10) //check for the amount of a dime
    {
        count++; //add one coin to the counter
        change_cents = change_cents - 10; //subtract the dime from the total
    }
    while (change_cents >= 5) //check for the amount of a nickel
    {
        count++; //add one coin to the counter
        change_cents = change_cents - 5; //subtract the nickel from the total
    }
    while (change_cents >= 1) //check for the amount of a penny
    {
        count++; //add one coin to the counter
        change_cents = change_cents - 1; //subtract the penny from the total
    }

    printf("%i\n", count); //display the minimum amount of coins needed
}