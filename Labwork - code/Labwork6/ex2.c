#include <stdio.h>
#include <stdlib.h>

typedef struct array
{
    int value;
    struct array* next;
}arr;

const int max = 42;

void random_array(arr* a, int size);

// Compare 2 numbers if the a is bigger return 1, if b is bigger return 0
int compare(int* a, int* b);

int main(void)
{
    arr* array = malloc(sizeof(arr) * 8);
    // Check
    if (array == NULL)
    {
        printf("allocate memory fail\n");
        return 1;
    }
   
    random_array(array, 8); 

    for (int i = 0; i < 8; i++)
    {
        printf("%d ", array[i].value);
    }

    free(array);
}

void random_array(arr* a, int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i].value = rand() % (max + 1);
    }
}

int compare(int* a, int* b)
{
    if (*a > *b)
    return 1;
    else if (*a < *b)
    return 0;
    else
    return 1;
}