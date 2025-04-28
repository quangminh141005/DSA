#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct car_list
{
    int capacity;
    int passenger;
    char* id;
    struct car_list* next;
}car_node;

// Create the head for link list
car_node* head;

car_node* create(int capac, int passen, char* aidi);
car_node* insert(int capac, int passen, char* aidi);
void print_car(car_node* car_head);
void free_car(car_node* car_head);

int main(void)
{
    // Create the head of the linked list 
    car_node* car1 = create(25, 14, "toyota");
    head = car1;
    car_node* car2 = insert(12, 5, "mitsubishi");
    car_node* car3 = insert(100, 45, "mazda");

    // Print the car link list
    print_car(head);
    free_car(head);
    
    return 0;    
}

car_node* create(int capac, int passen, char* aidi)
{
    car_node* car = malloc(sizeof(car_node));
    if (car == NULL)
    {
        return 0;
    }
    car->capacity = capac;
    car->passenger = passen;
    car->id = malloc(strlen(aidi)+1);
    strcpy(car->id, aidi);
    car->next = NULL;
    
    return car;
}

car_node* insert(int capac, int passen, char* aidi)
{
    car_node *car = malloc(sizeof(car_node));
    if (car == NULL)
    {
        return 0;
    }
    car->capacity = capac;
    car->passenger = passen;
    car->id = malloc(strlen(aidi)+1);
    strcpy(car->id, aidi);
    car->next = head;
    head = car;

    return car;
}

void print_car(car_node* car_head)
{
    car_node* temp = car_head;
    
    int i = 1;
    while (temp != NULL)
    {
 
        printf("Car %d have the capacity of %d, have %d passengers, id: %s\n", i, temp->capacity, temp->passenger, temp->id);
        temp = temp->next;
        i++;
    }
    return;
}

void free_car(car_node* car_head)
{
    car_node* temp = car_head;

    while(car_head != NULL)
    {
        temp = car_head->next;
        free(car_head->id);
        free(car_head);
        car_head = temp;
    }
    return;
}