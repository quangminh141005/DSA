#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct helo
{
    int value;
    struct helo* left;
    struct helo* right;
}leaf;

void printTree(leaf* a);

int isPrime(int a);
leaf* factor_tree(int a);

int main(void)
{
    int x = 3240;
    leaf* node = factor_tree(x);
    printTree(node);
    printf("\n");
    return 0;
}

int isPrime(int a)
{
    if (a == 2)
    {
        return 1;
    }

    if (a < 2 || a % 2 == 0)
    {
        return 0;
    }

    for (int i = 3; i < sqrt(a); i+= 2)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

leaf* factor_tree(int a)
{
    leaf* node = malloc(sizeof(leaf));
    if (node == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    node->value = a;
    if (isPrime(a) == 1)
    {
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            node->left = factor_tree(a/i);
            node->right = factor_tree(i);
            return node;                        
        }
    }
}

void printTree(leaf* a)
{
    if (a == NULL)
    {
        return;
    }

    if (a->left == NULL && a->right == NULL)
    {
        printf("%d*", a->value);
        return;
    }

    printTree(a->left);
    printTree(a->right);
}