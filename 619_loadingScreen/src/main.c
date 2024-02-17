#include <stdio.h>
#include <stdlib.h>

int *getImageSize();
int length(int *);

int main()
{
    // Array Pointer: [X,Y].
    int *imageSize;

    imageSize = getImageSize();

    if (imageSize != NULL)
    {
        for (size_t i = 0; i < 2; i++)
        {
            printf("%d ", *(imageSize + i));
        }
        

        free(imageSize);
    }
    else
    {
        printf("Can't get image size.");
    }
    printf("\n");
    return 0;
}

// Get image size pixels [X Y].
// Checks if it's values are multiples of 8.
int *getImageSize()
{
    int *imageSize = malloc(2 * sizeof(int));

    if (imageSize != NULL)
    {
        printf("Introduce la resolucion de la imágen (X Y): ");
        scanf("%d %d", imageSize, imageSize + 1);
    }

    return imageSize;
}

// Returns the length of a given array.
int length(int *array)
{
    int length = 0;
    if (array != NULL)
    {
        while (*(array + length) != '\0')
        {
            length++;
        }
    }
    return length;
}