#include <stdio.h>

int isPrime(int a);
void factorization(int a);

int main(void)
{
    int x = 84;
    printf("%d = ", x);
    factorization(x);
    printf("\n");
    return 0;
}

int isPrime(int a)
{
    if (a == 2)
    {
        return 1;
    }

    if (a < 2 || a % 2 == 0)
    {
        return 0;
    }

    for (int i = 0; i < a; i+= 2)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void factorization(int a)
{
    if (a == 1)
        return;
    for (int i = 2; i <= a; i++)
    {
        if (a % i == 0 && a / i != 1)
        {
            printf("%d*", i);
            return factorization(a/i);
        }
        else if (a % i == 0 && a / i == 1)
        {
            printf("%d", i);
            return factorization(a/i);
        }
    }
}