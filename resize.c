/**************************************************************
 * resize.c
 * CS50
 * Problem Set 4
 * 
 * This program resize a bmp file by a factor of n
 * ************************************************************/

#include <stdio.h>
#include <cs50.h>

#include "bmp.h"

int main(int argc, char *argv[])

{
    // check the number of command-line arguments
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }
    
    // remember and convert factor; remember filenames
    int n = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];
    
    
    if ( n < 1 || n > 100)
       {
            fprintf(stderr, "n must be a postive integer less than or equal to 100\n");
            return 1;
       }
       
    // open and check reading access of infile
    FILE *inptr = fopen(infle,"r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    
    // open and check writing access of outfile
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr,"Could not create %s.\n",outfile);
        return 3;
    }
    
    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, bf_r;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bf_r = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, bi_r;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    bi_r = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    
    // Define the new size of the image
    bi_r.biWidth = bi.biWidth * n;
    bi_r.biHeight = bi.biHeight *n;
    
    // determine padding for scanlines for the old and new image
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int new_padding = (4 - (bi_r.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // define new image's size
    bi_r.biSizeImage = (bi_r.biWidth * sizeof(RGBTRIPLE) + new_padding) * abs(bi_r.bHeight);
    bf_r.bSize = bf.bfSize - bi.biSizeImage + bi_r.biSizeImage;
    
     // write outfile's BITMAPFILEHEADER
    fwrite(&bf_r, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_r, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over each scanline n times
        for (int j = 0; j < n; j++)
        {
            
            // iterate over pixels in scanline
            for (int k = 0; k < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
    
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
    
                // write RGB triple to outfile times n
                for (int l = 0; l < n; l++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);   
                }
                
            }
            
            // new padding for resized image
            for (int l = 0; l < new_padding; l++)
            {
                fputc(0x00, outptr);
            }
    
            // return to beginning of each scanline
            fseek(inptr, -bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);

        }
        
         // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
        
    }
    
    // success
    return 0;
}