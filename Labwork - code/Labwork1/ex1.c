#include <stdio.h>
#include <math.h>

int main(void)
{
    int a;
    printf("Enter the number\n");
    scanf("%d", &a);
    // Count how manu digit in the number
    int count = 0;
    int copy_a = a;
    while (copy_a != 0)
    {
        copy_a /= 10;
        count++;
    }

    // Put the number into a array
    int number[count];
    int copy2_a = a;
    for (int i = 0; i < count; i++)
    {
        number[i] = copy2_a % 10;
        copy2_a /= 10;
    }
    // Switch the last digit and the first digit
    int temp;
    temp = number[0];
    number[0] = number[count - 1];
    number[count - 1] = temp;

    // Put the array into number
    a = 0;
    for (int i = 0; i < count; i++)
    {
        a += number[i] * pow(10,i);
    }
    printf("This is the number after switch: %d\n", a);

    return 0;
}
