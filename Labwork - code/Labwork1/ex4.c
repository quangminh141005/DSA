#include <stdio.h>

int check_prime(int a);
int check_sphenic(int a);

int main(void)
{
    int temp;
    printf("Enter a number to test: ");
    scanf("%d", &temp);
    if (check_sphenic(temp) == 1)
    {
        printf("%d is a sphenic number\n", temp);
        return 0;
    }
    else printf("%d is NOT a sphenic number\n", temp);
    
    return 0;
}

int check_sphenic(int a)
{
    int count = 0;
    int temp = a;
    for (int i = 2; i < temp/2; i++)
    {
        if (check_prime(i) == 1)
        {
            if (a % i == 0 && a >= i)
            {
                a /= i;
                count++;
            }
        }
    }

    if (count == 3)
    {
        return 1;
    }

    return 0;
}

int check_prime(int a)
{
    if (a == 2)
        return 1;
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

