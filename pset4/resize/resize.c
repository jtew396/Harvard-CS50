/**
 * J.T. Williams
 *
 * Tech901 Code1.0
 *
 * CS50
 *
 * Problem Set 4
 *
 * resize.c less
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy n infile outfile\n");
        return 1;
    }

    // remember n and check for validity
    int n = atoi(argv[1]);
    if (n <= 0 || n > 100)
    {
        fprintf(stderr, "n must be a positive integer less than or equal to 100");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    //make a copy of the original biWidth
    int biWidthIn = bi.biWidth;
    int biHeightIn = abs(bi.biHeight);

    printf("biWidthIn: %i \n", biWidthIn);
    printf("biHeightIn: %i \n", biHeightIn);

    //scale up the width and height by n
    bi.biWidth *= n;
    bi.biHeight *= n;

    printf("bi.biWidth: %i \n", bi.biWidth);
    printf("bi.biHeight: %i \n", bi.biHeight);

    // determine outfile padding for scanlines
    int paddingIn = (4 - (biWidthIn * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    printf("%i %i\n", paddingIn, padding); //print the padding integers to check for accuracy

    //update the image and file size
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    //allocate enough memory for the scanline
    RGBTRIPLE *PixelRow = malloc(bi.biWidth * sizeof(RGBTRIPLE));

    // iterate over infile's scanlines
    for (int i = 0; i < biHeightIn; i++)
    {
            //position of PixelRow
            int position = 0;

            // iterate over pixels in scanline
            for (int j = 0; j < biWidthIn; j++)
            {

                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write pixel to PixelRow
                for (int l = 0; l < n; l++)
                {
                    PixelRow[position] = triple;
                    position++;
                    printf("RGB[%d][%d]: (%u, %u, %u)\n PixelRow[%i]\n", j, l, PixelRow[l].rgbtRed, PixelRow[l].rgbtGreen, PixelRow[l].rgbtBlue, position);
                }

            }

            // skip over padding, if any
            fseek(inptr, paddingIn, SEEK_CUR);

            //write the array to the out file
            for(int m = 0; m < n; m++)
            {
                //write the pixel to the out file
                for(int o = 0; o < bi.biWidth; o++)
                {
                    fwrite(&PixelRow[o], sizeof(RGBTRIPLE), 1, outptr);
                }

                //write the padding to the outfile
                for (int k = 0; k < padding; k++)
                {
                    fputc(0x00, outptr);
                }
            }
   }

    //free up the memory
    free(PixelRow);

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
