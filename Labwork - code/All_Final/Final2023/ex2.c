#include <stdio.h>
#include <stdlib.h>

typedef struct helo
{
    int value;
    struct helo* left;
    struct helo* right;
}leaf;

leaf* create(int data);
void print_tree(leaf* node);
void free_tree(leaf* node);

int main(void)
{
    // Create the tree
    leaf* node = create(10);
    node->left = create(4);
    node->right = create(8);
    node->left->right = create(13);
    node->right->left = create(20);
    node->right->right = create(90);

    print_tree(node);
    free_tree(node);
}

leaf * create(int data)
{
    leaf* node = malloc(sizeof(leaf));
    node->value = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void print_tree(leaf* node)
{
    if (node == NULL)
        return;
    int front = 0;
    int rear = 0;

    leaf* queue[100];

    queue[rear++] = node;

    while (front < rear)
    {
        leaf* temp = queue[front++];
        printf("%d ", temp->value);

        if (temp->left != NULL)
        {
            queue[rear++] = temp->left;
        }

        if (temp->right != NULL)
        {
            queue[rear++] = temp->right;
        }
    }

    printf("\n");
}

void free_tree(leaf* node)
{
    if (node == NULL)
    {
        return;
    }

    free_tree(node->left);
    free_tree(node->right);
    free(node);
}