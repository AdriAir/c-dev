#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "./shared/functions.h"

int main()
{
    // Array length for X and Y image size values.
    const size_t IMAGE_SIZE_LENGTH = 2;

    // Image size pointer for an array with X and Y values.
    int *imageSize;

    // Pointers of an char array (string) pointers.
    char **imageData;

    imageSize = getImageSize(IMAGE_SIZE_LENGTH);

    if (validateImageInput(imageSize, IMAGE_SIZE_LENGTH))
    {
        imageData = (imageData, *imageSize, *(imageSize + 1));
        // TODO: CHECK IF MATRIX IS VALID
    }
    disposeArray(imageSize);
    return 0;
}

// Given an empty array of string pointers (array of arrays of chars), user will fill it in with chars.
// The given array should looks like: [stringPointer(X length) * Y]
char **getImageData(char **imageData, size_t xSize, size_t ySize)
{
    //TODO: Malloc X and Y
}