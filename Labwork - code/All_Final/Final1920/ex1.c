#include <stdio.h>
#include <math.h>

int isPrime(int a);
int isSphenic(int a, int count);

int main(void)
{
    int a[] ={30,27, 42, 66, 70, 78, 102, 105, 110, 114, 130, 138, 154, 165};
    int size = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < size; i++)
    {
        if (isSphenic(a[i], 0) == 1)
        {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
    return 0;
}

int isPrime(int a)
{
    if (a < 2 || a % 2 == 0)
    {
        return 0;
    }
    if (a == 2)
    {
        return 1;
    }

    int temp = sqrt(a);

    for (int i = 3;  i < temp; i += 2)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int isSphenic(int a, int count) 
{
    // Base case
    if (a == 1 && count == 3)
    {
        return 1;
    }

    if (count > 3 || a == 1)
    {
        return 0;
    }


    for (int i = a - 1; i >= 2; i--)
    {
        if (isPrime(i) == 1 && a % i ==0)
        {
            return isSphenic(a / i ,count + 1);
        }
    }

}