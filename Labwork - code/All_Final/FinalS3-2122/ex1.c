#include <stdio.h>

int gcd(int a, int b);
void find_coprime(int * a, int size);

int main(void)
{
    int a[] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50};
    int size = sizeof(a) / sizeof(a[0]);

    find_coprime(a, size);
    return 0;    
}

int gcd(int a, int b)
{
    
    while (b != 0)
    {
    int temp = b;
    b = a % b;
    a = temp;
    }

    return a;
}

void find_coprime(int* a, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (gcd(a[i], a[j]) == 1)
            {
                printf("%d %d\n", a[i], a[j]);
            }
        }
    }
}