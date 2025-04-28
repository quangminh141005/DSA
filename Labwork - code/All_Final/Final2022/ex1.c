#include <stdio.h>
#include <math.h>

// Return 1 if prime, else return 0
int isprime(int a);
void findprime(int* a, int count, int size);
void findtwin();

int temp[100];
int count_arr = 0;

int main(void)
{
    int a[] = {3 , 101, 96, 41, 7, 65, 9, 13, 5, 79, 45, 30, 11, 43};
    int size = sizeof(a) / sizeof(a[0]);
    findprime(a, 0, size);
    findtwin();

    return 0;
}

int isprime(int a)
{
    if (a == 2)
    {
        return 1;
    }

    if (a % 2 == 0 || a < 2)
    {
        return 0;
    }

    for (int i = 3; i < a; i++)
    {
        if (a % i == 0)
        return 0;
    }
    return 1;
}

void findprime(int* a, int count, int size)
{
    if (count == size)
    {
        return;
    }

    if (isprime(a[count]) == 1)
    {
        temp[count_arr++] = a[count];
    }

    findprime(a, count + 1, size);
}

void findtwin()
{
    for (int i = 0; i < count_arr - 1; i++)
    {
        for (int j = i + 1; j < count_arr; j++)
        {
            if (temp[i] + 2 == temp[j] || temp[i] - 2 == temp[j])
            {
                printf("%d %d\n", temp[i], temp[j]);
            }
        }
    }
}