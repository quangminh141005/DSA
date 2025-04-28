#include <stdio.h>

void selection_sort(int* a, int size);
void swap(int* a, int* b);
void recurselect(int * a, int size);

int main(void)
{
    int a[] = {6,2,4,9,1,12,7,17,5};
    int size = sizeof(a) / sizeof(a[0]);
    selection_sort(a, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

void selection_sort(int * a, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int temp = i;
        for (int j = i + 1; j < size; j++)
        {
            

            if (a[temp] > a[j])
            {
                temp = j;
            }
        }
        if (temp != i)
        {
            swap(&a[i], &a[temp]);
        }
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void recurselect(int * a, int size)
{
    
}