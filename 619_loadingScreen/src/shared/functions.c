#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "functions.h"

// Dispose dynamic arrays if exists
void disposeArray(int *array)
{
    if (array != NULL)
    {
        free(array);
    }
}

// Dispose dynamic matrix if exists
void disposeMatrix(char **matrix, size_t length)
{
    if (matrix != NULL)
    {
        for (size_t i = 0; i < length; i++)
        {
            if (*(matrix + i) != NULL)
            {
                free((matrix + i));
            }
        }
        free(matrix);
    }
}

// Valdates image vector input
bool validateImageInput(int *imageSize, size_t length)
{
    if (imageSize != NULL)
    {
        if (checkIfIsInRange(imageSize, length))
        {
            if (checkMultiple(imageSize, length, 8))
            {
                return true;
            }
            printf("Both values must be multiples of 8.\n");
            fflush(stdout);

            return false;
        }
        printf("Both numbers must be positive numbers.\n");
        fflush(stdout);

        return false;
    }
    printf("Can't get image size.\n");
    fflush(stdout);

    return false;
}

// Get image size pixels [X Y].
int *getImageSize(size_t length)
{
    int *imageSize = malloc(length * sizeof(int));

    if (imageSize != NULL)
    {
        printf("Introduce la resolucion de la imágen (X Y): ");
        fflush(stdout);
        scanf("%d %d", imageSize, imageSize + 1);
        fflush(stdin);
    }

    return imageSize;
}

// Given an empty array of string pointers (array of arrays of chars), user will fill it in with chars.
// The given array should looks like: [Y * stringPointer(X * char)]
char **getImageData(char **imageData, size_t xSize, size_t ySize)
{
    imageData = malloc(ySize + sizeof(char *));
    printf("Introduce el vector de colores de la imágen (%zu filas; %zu columnas): \n", ySize, xSize);
    fflush(stdout);
    for (size_t i = 0; i < ySize; i++)
    {
        /**
         * @bug DATA IS NOT SAVED OK (SHOULD BE BECAUSE FFLUSH OR OUR MATRIX STRUCTURE)
         */
        *(imageData + i) = malloc((xSize * sizeof(char)) + 1);
        fgets(*(imageData + i), sizeof(xSize * sizeof(char) + 1), stdin);
    }
    *(imageData + ySize) = '\0';
    return imageData;
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
bool checkIfIsInRange(int *numbers, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        if (*(numbers + i) <= 0 || *(numbers + i) > 48)
        {
            return false;
        }
    }
    return true;
}