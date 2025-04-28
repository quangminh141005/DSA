#include <stdio.h>

void findMax(int *max, int a);

int main(void)
{
    int current;
    
    int input;
    printf("Enter the max value: ");
    scanf("%d", &current);
    
    printf("Enter new value: ");
    scanf("%d", &input);
   
    printf("The old max value is: %d", current);
    printf("\n");
    findMax(&current, input);
    printf("The new max value is: %d", current);
  
    return 0;
}

void findMax(int *max, int a)
{
    if (a > *max)
    {
        *max = a;
    }   
    
}