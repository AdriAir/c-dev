#ifndef functions_h
#define functions_h

void disposeArray(int *);
void disposeMatrix(char **, size_t);
int *getImageSize(size_t);
bool checkMultiple(int *, size_t, int);
bool checkIfIsInRange(int *, size_t);
bool validateImageInput(int *, size_t);
char **getImageData(char **, size_t, size_t);

#endif