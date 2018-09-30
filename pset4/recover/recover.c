/**
 * J.T. Williams
 *
 * Tech901 Code1.0
 *
 * CS50 Problem Set 4
 *
 * recover.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Correct usage: ./recover image");
        return 1;
    }

    char* infile = argv[1];
    printf("%s", infile);


    // open input file
    FILE* file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    //open out file
    //FILE* img;

    //allocate enough memory for the JPEG
    /* BYTE* buffer = malloc(512 * sizeof(BYTE));
    if(buffer == NULL)
    {
        return 2;
    }
    */

    unsigned char buffer[512];
    int JPEGTracker = 0;
    int JPEGNew = 0;
    char filename[8];

    FILE* img = NULL;

    /*
    if (img == NULL)
    {
        fclose(img);
        fprintf(stderr, "Could not open %s. \n", filename);
        return 2;
    }
    */


    //use a while loop while reading the file
    while(fread(buffer, 512, 1, file) == 1)
    {

        //track how many JPEGs
        printf("%i", JPEGTracker);

        //read into the file 512 bytes 1 block each
        //fread(buffer, 512, 1, file);

        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            //check if JPEG has been opened
            if(JPEGNew == 1)
            {
                fclose(img);
            }
            else
            {
                JPEGNew = 1;
            }

        sprintf(filename, "%03i.jpg", JPEGTracker);
        img = fopen(filename, "w");
        JPEGTracker++;
            /*
            if (img == NULL)
            {
                fclose(img);
                fprintf(stderr, "Could not open %s. \n", filename);
                return 2;
            }
            */

        }

        if(JPEGNew == 1)
        {
            fwrite(&buffer, 512, 1, img);
        }

        //break at end of file
        //if(feof(file))
        //{
        //    break;
        //}
    }

    //free up the malloc memory
    //free(buffer);

    //close the opened file
    fclose(file);
    fclose(img);

    //success
    return 0;

}