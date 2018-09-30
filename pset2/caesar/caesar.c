/****************************
 * JT Williams              *
 * Tech901                  *
 * CS50 Problem Set 2       *
 * caesar.c                 *
 ****************************/

 #include <stdio.h>
 #include <cs50.h>
 #include <ctype.h>
 #include <string.h>
 #include <stdlib.h>


//start a main block for command line input
 int main(int argc, string argv[])
 {

  if(argc != 2)
  {

   printf("ERROR\n");
   return 1;

  }

   //declare ks as a string of argv[1]
   string ks = argv[1];

   //convert ki to an integer
   int ki = atoi(ks);

   printf("plaintext: ");

   //declaring & prompting the user for plaintext
   string plaintext = get_string();

   //print ciphertext
   printf("ciphertext: ");

   for (int i = 0, n = strlen(plaintext); i < n; i++)
   {

    //check if the char is alphabetic
    if (isalpha(plaintext[i]))
    {

     //preserve the case of the char
     if (isupper(plaintext[i]))
     {
      //print the capital char by the key
      printf("%c", ((plaintext[i] + ki - 65) % 26) + 65);

     }
     else
     {

      //print the lower case char by the key
      printf("%c", ((plaintext[i] + ki - 97) % 26) + 97);

     }

    }
    else
    {

     //if the char for plaintext[i] is not alphabetic, return the char
     printf("%c", plaintext[i]);

    }

   }

   //print new line
   printf("\n");

 }
