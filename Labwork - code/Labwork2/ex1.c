#include <stdio.h>
#include <stdlib.h>

typedef struct interger
{
    int size;
    int data[1000];
} integer;

const int CAPACITY = 1000;

integer* init(int s);
void add(integer* p, int value, int index);
void removee(integer* p, int index);
void calculate(integer* p);
void display(integer* p);
void free_arr(integer* p);

int main(void)
{
    //Enter the integer
    integer *p = init(7);

    for (int i = 1; i < 7; i++)
    {
        p->data[i] = i;
    }

    add(p, 4, 3);
    display(p);
    removee(p, 3);
    display(p);
    calculate(p);
    display(p);
    free_arr(p);
    
    return 0;   
}

integer* init(int s)
{
    integer* numb = malloc(sizeof(integer));
    numb->size = s;
    return numb;
}

void add(integer* p, int value, int index)
{
    if (p->size == 1000)
    {
        printf("Can't not add more items to the list\n");
        return;
    }

    if (index < 0 || index > p->size)
    {
        printf("illegal index\n");
        return;
    }
    // add new digits at any place in an integer
    for(int i = p->size; i > index + 1; i--)
    {
        p->data[i+1] = p->data[i];
    }
    p->data[index + 1] = value;
    p->size++;
}

void removee(integer* p, int index)
{
    // remove a digit at a specfic position in an integer
    if (p->size == 0)
    {
        printf("Can't not remove more items to the list\n");
        return;
    }

    if (index < 0 || index > p->size)
    {
        printf("illegal index\n");
        return;
    }

    for (int i = index - 1; i < p->size - 1; i++)
    {
        p->data[i] = p->data[i + 1];
    }
    p->size--;
}

void calculate(integer* p)
{
    // calculate the sum of all digits from an unbounded integer
    int sum = 0;
    for (int i = 0; i < p->size; i++)
    {
       sum += p->data[i]; 
    }
    printf("The sum of the integer: %d\n", sum);
}

void display(integer* p)
{
    // display the whole number on the screen
    for(int i = 0; i < p->size; i++)
    {
        printf("%d",p->data[i]);
    }
    printf("\n");
}

void free_arr(integer* p)
{
    if (p == NULL)
    {
        return;
    }
    free(p);
}