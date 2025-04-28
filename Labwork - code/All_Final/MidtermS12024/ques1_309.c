#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool check_pythago(int a[],int size);

int main(void)
{
    int a[] = {3, 5, 4};
    if (check_pythago(a, 3))
    {
        printf("This is a pythagorean triple\n");
        return 0;
    }
    else 
    {
        printf("This is NOT a pythagorean triple\n");
        return 0;
    }
}

bool check_pythago(int a[], int size)
{
    int sum = pow(a[0],2) + pow(a[1],2) + pow(a[2],2);
    for (int i = 0; i < 3; i++)
    {
        if (pow(a[i], 2) == (sum - pow(a[i],2)))
        {
            return true;
        }
    }
    return false;
}