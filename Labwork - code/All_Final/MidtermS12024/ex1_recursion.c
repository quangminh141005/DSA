#include <stdio.h>

int check_pythagon(int a[], int size);

int main(void)
{
    int a[3] = {6, 8, 13};
   if (check_pythagon(a, 2) == 0)
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

int check_pythagon(int a[], int size)
{
    int sum = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
    
    if (a[size] * a[size] == sum - a[size] * a[size])
    {
        return 0;
    }
    if (size == 0)
    {
        return 1;
    }
    return check_pythagon(a, size - 1);
}