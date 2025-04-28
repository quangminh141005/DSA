#include <stdio.h>

int centercube(int n);

// Return 1 if true, 0 if false
int check_centercube(int* a, int size, int i);

int main(void)
{
    int a[] = {9,35,84};

    int size = sizeof(a) / sizeof(a[0]);
    
    if (check_centercube(a, size, 0) == 1)
    {
        printf("The values in the given array are center cube\n");
    }
    else
    printf("The values in the given array are NOT center cube\n");
}

int centercube(int n)
{
    return n * n * n + (n + 1) * (n + 1) * (n + 1);
}

int check_centercube(int * a, int size, int i)
{
    if (i == size)
    {
        return 1;
    }

    int n = 1;
    while (centercube(n) < a[i])
    {
        n++;
    }

    if (centercube(n) == a[i])
    {
        check_centercube(a, size, i + 1);
    }

    return 0;

}