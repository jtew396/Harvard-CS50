/****************************
 * JT Williams              *
 * Tech901                  *
 * CS50 Problem Set 2       *
 * viginere.c               *
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

   //declare k as a string of argv[1]
   string k = argv[1];

   for(int i = 0, n = strlen(k); i < n; i++)
   {

    if(isalpha(k[i]))
    {

    }
    else
    {

     printf("ERROR\n");
     return 1;

    }
   }

   printf("plaintext: ");

   //declaring & prompting the user for plaintext
   string plaintext = get_string();

   //print ciphertext
   printf("ciphertext: ");

   for (int i = 0, n = strlen(plaintext); i < n; i++)
   {
    if(isalpha(plaintext[i]))
    {
     //preserve the case of the char
     if (isupper(plaintext[i]))
     {

      //print the capital char by the key
      printf("%c", ((plaintext[i] + (toupper(k[i % strlen(k)]) - 65) - 65) % 26) + 65);

     }
     else
     {

      //print the lower case char by the key
      printf("%c", ((plaintext[i] + (toupper(k[i % strlen(k)]) - 65) - 97) % 26) + 97);

     }
    }
    else
    {

     printf("%c", plaintext[i]);

    }
   }

   //print new line
   printf("\n");

 }
