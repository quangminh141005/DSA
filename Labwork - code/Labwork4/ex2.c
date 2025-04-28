#include <stdio.h>

int check_prime(int a, int b);
int check_sphenic(int a);

int count = 0;

int main(void)
{
   int a = 1231;
   if (check_sphenic(a) == 1)
    {
        printf("%d is the sphenic number\n", a);
        return 0;
    }
    else
    {
        printf("%d is NOT the sphenic number\n", a);
        return 1;
    }
}

int check_prime(int a,int b)
{
    // If 1 is the prime number if not return 0 
    if (a == 2 )
    return 1;

    if (a <= 1)
    return 0;

    if (a % b == 0)
    {
        return 0;
    }
    if (b == 2)
    {
        return 1;
    }
    if (a % b != 0)
    return check_prime(a, b - 1);
}

int check_sphenic(int a)
{
    
    if (count > 3 || count < 3 || (a == 0 && count != 3))
    {
        return 0;
    }
    if (a == 0 && count == 3)
    {
        return 1;
    }
    if (checkprime(a) == 0)
}