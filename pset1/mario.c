//JT Williams
//mario.c program

#include <stdio.h>
#include <cs50.h>

int space = 0; //declared space to be used later
int hash = 0; //declared hash to be used later
int i = 0; //declared i to be used later

int main(void)
{
    int height; //declaring an integer height
    do
    {
        printf("What is the height: ");
        height = get_int(); //gathering input for height
    }
    while (height < 0 || height > 23);
    for (i = 0; i < height; i++)
    {
        for (space = 1; space < height - i; space++)
        {
            printf(" ");
        }
        for (hash = -1; hash < height - space; hash++)
        {
            printf("#");
        }
        printf("  ");
        for (hash = -1; hash < height - space; hash++)
        printf("#");
        printf("\n");
    }
}