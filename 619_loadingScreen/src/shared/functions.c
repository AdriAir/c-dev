#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "functions.h"

// Dispose dynamic arrays if exists
void disposeArray(void *array)
{
    if (array != NULL)
    {
        free(array);
    }
}
// Valdates image vector input
bool validateImageInput(int *imageSize, size_t length)
{
    if (imageSize != NULL)
    {
        if (checkIfIsPositive(imageSize, length))
        {
            if (checkMultiple(imageSize, length, 8))
            {
                return true;
            }
            printf("Both values must be multiples of 8.\n");
            return false;
        }
        printf("Both numbers must be positive numbers.\n");
        return false;
    }
    printf("Can't get image size.\n");
    return false;
}

// Get image size pixels [X Y].
int *getImageSize(size_t length)
{
    int *imageSize = malloc(length * sizeof(int));

    if (imageSize != NULL)
    {
        printf("Introduce la resolucion de la imágen (X Y): ");
        scanf("%d %d", imageSize, imageSize + 1);
    }

    return imageSize;
}
// Get image pixels [Y1[X_CHARS], Y2[]...].
int *getImageData(size_t rows, size_t pixelsPerRow)
{
    // char *image = malloc(length * sizeof(int));

    // if (imageSize != NULL)
    // {
    //     printf("Introduce la resolucion de la imágen (X Y): ");
    //     scanf("%d %d", imageSize, imageSize + 1);
    // }

    // return imageSize;
}

// Checks if every value of an array it's multiple of a base integer value
bool checkMultiple(int *numbers, size_t length, int base)
{
    for (size_t i = 0; i < length; i++)
    {
        if (*(numbers + i) % base != 0)
        {
            return false;
        }
    }
    return true;
}

// Checks if every value of an array it's a positive number
bool checkIfIsPositive(int *numbers, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        if (*(numbers + i) <= 0)
        {
            return false;
        }
    }
    return true;
}