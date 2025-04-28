#include <stdio.h>

const int CAPACITY = 1000;

typedef struct stock;
{
    char name[50];
    int quantity;
    int price;
}   stock;

typedef struct customer
{
    char name[50];
    stock item[50];
    int quantity;
}   customer;

typedef struct queue
{
    customer customer[CAPACITY];
    int back;
}   queue;

void init(queue *p);
void display(queue *p);
void enqueue(queue* p);
void dequeue(queue* p);

int main(void)
{
    stock stocks[3];
    stocks = {"Apple", 30, 40}, {"Lemon, 10, 10"}, {"pine", 20, 30};
    queue *p = malloc(sizeof(queue));
    // Initilize the queue
    init(p);

    // Give the queue the number of customers (and what they are bying)
    customer customers[4];
    customers = {"Alice", stocks[0], 10}, {"Bob", stocks[0], 50}, {"Peter", stock[1], 10}, {"Paul", stock[2], 10};

    // Take turn to buy the product

    // Display the message if sucessdful or a warning message

    // free the queue
    free(p);
}

void init(queue *p)
{
    p->back = 0;
}

void display(queue *p)
{

}

void enqueue(queue *p)
{
    p->back++;
}

void dequeue(queue *p)
{
    p->back--;
}