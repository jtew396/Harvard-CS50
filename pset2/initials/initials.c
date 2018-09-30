//JT Williams
//initials.c script

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    //prompt user for input
    string name = get_string();

    //check get_string returned a string
    if (name != NULL)
    {
        //iterate over the characters in name
        for (int i = 0; i < strlen(name); i++)
        {
            if (i == 0)
            {
                //print the first string character as uppercase
                printf("%c", toupper(name[0]));
            }
            else if (name[i] == ' ')
            {
                //if the string character is \0 then print the following character
                printf("%c", toupper(name[i + 1]));
            }

        }

    }

    //print a new line
    printf("\n");

}