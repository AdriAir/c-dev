#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "./shared/functions.h"

int main(int argc, char const *argv[])
{
    // Array length for X and Y image size values.
    const size_t IMAGE_SIZE_LENGTH = 2;

    // Image size pointer for an array with X and Y values.
    int *imageSize;

    // Pointers of an array of strings (arrays of chars) pointers.
    char **imageData;

    imageSize = getImageSize(IMAGE_SIZE_LENGTH);

    if (validateImageInput(imageSize, IMAGE_SIZE_LENGTH))
    {
        imageData = getImageData(imageData, *imageSize, *(imageSize + 1));

        for (size_t i = 0; i < *(imageSize + 1); i++)
        {
            for (size_t j = 0; j < *imageSize; j++)
            {
                printf("%c", *(*(imageData + i) + j));
                fflush(stdout);
            }
            printf("\n");
            fflush(stdout);
        }

        // TODO: CHECK IF MATRIX IS VALID

        disposeMatrix(imageData, *(imageSize + 1));
    }
    disposeArray(imageSize);
    return 0;
}