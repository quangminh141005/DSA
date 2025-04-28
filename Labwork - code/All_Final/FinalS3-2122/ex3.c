#include <stdio.h>
#include <stdlib.h>

typedef struct helo
{
    int value;
    struct helo* next;
}node;

node* insert(int a, node* head);
int gcd(int a, int b);
void find_coPrime(node* head);

int main(void)
{
    int a[] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50};
    int size =  sizeof(a) / sizeof(a[0]);

    node* head = malloc(sizeof(node));
    head = NULL;

    for (int i = 0; i < size; i++)
    {
        head = insert(a[i], head);
    }
    find_coPrime(head);
    return 0;
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return  gcd(b, a % b);
}

node* insert(int a, node* head)
{
    node* temp = malloc(sizeof(node));
    temp->value = a;
    temp->next = head;

    return temp;
}

void find_coPrime(node* head)
{
    node* head1 = head;
    while (head1 != NULL)
    {
        node* head2 = head1->next;
        while (head2 != NULL)
        {
            if (gcd(head1->value, head2->value) == 1)
            {
                printf("%d %d\n", head1->value, head2->value);
            }
            head2 = head2->next;
        }
        head1 = head1->next;
    }
}