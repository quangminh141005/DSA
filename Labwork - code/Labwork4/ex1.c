#include <stdio.h>

int digit_sum(int a); 

int main(void)
{
    int a = 103509;
    printf("The sum of all digit of %d is %d\n", a, digit_sum(a));
    return 0;
}

int digit_sum(int a)
{
    if (a == 0)
        return 0;
    return a % 10 + digit_sum(a / 10);
}