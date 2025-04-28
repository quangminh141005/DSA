#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int const LIMIT = 100;

typedef struct helo
{
    int value;
    struct helo* left;
    struct helo* right;
}leaf;

// Create a binary tree
leaf* small(int* a, int len);

// Create a random array
int* ran_arr(int n);
int max(int* a, int size);

// Display tree (pre-order)
void display_tree(leaf* root, int size);

// Free tree
void freetree(leaf* a);

int main(void)
{
    int n = 9;
    int size = pow(2, ceil(log2(n)));

    int * a = ran_arr(n);

    // print the arr
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    leaf* tree = small(a, size);

    printf("%d", tree->value);
    printf("\n");

    display_tree(tree, 0);
    printf("\n");

    free(a);
    freetree(tree);
}

leaf* small(int* a, int len)
{
    if (len == 0) return NULL;

    leaf* node = malloc(sizeof(leaf));
    // Base case
    if (len == 1)
    {
        node->value = a[0];
        node->left = NULL;
        node->right = NULL;

        return node;
    }

    // Spilt into 2 array
    int len_left = len / 2;
    int len_right = len - len_left;
    int* a_left = malloc(sizeof(int) * len_left);
    int* a_right = malloc(sizeof(int) * len_right);
 
    for (int i = 0; i < len_left; i++)
    {
        a_left[i] = a[i];
    }

    for (int i = len_left; i < len; i++)
    {
        a_right[i - len_left] = a[i];
    }

    //  recursively find the smaller node
    node->left = small(a_left, len_left);
    node->right = small(a_right, len_right);

    // Connect 2 node to the smaller node
    if (node->left->value < node->right->value)
    {
        node->value = node->left->value;
    }
    else
    {
        node->value =  node->right->value;
    }

    free(a_right);
    free(a_left);

    return node;
}

int max(int * a, int size)
{
    int num_max = a[0];
    for (int i = 0; i < size; i++)
    {
        if (num_max < a[i])
        {
            num_max = a[i];
        }
    }

    return num_max;
}


int* ran_arr(int n)
{
    int size = pow(2, ceil(log2(n)));

    int* arr = malloc(sizeof(int) * size);

    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % LIMIT ;
    }

    int E = max(arr, n) + 1;

    for (int i = n; i < size; i++)
    {
        arr[i] = E;
    }

    return arr;

}

void display_tree(leaf* root, int size)
{
    // RIGHT->NODE->LEFT
    if (root == NULL)
        return;

        display_tree(root->right, size+1);
        for (int i = 0; i < size; i++)
        {
            printf("           ");
        }
        printf("%d", root->value);
        printf("\n");
        display_tree(root->left,size+1);
}

void freetree(leaf* a)
{
    if (a == NULL)
    {
        return;
    }

    freetree(a->left);
    freetree(a->right);
    free(a);
}
