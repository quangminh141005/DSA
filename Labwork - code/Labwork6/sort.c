#include <stdio.h>
#include <stdlib.h>

void swap(int*aa, int* bb);
void selection(int* a, int len);
void bubble(int* a, int len);
void merge(int* a, int len);
void selection_recursion(int* a, int len, int count);


int main(void)
{
    int arr[] = {4,9,12,5,7,2,34,14,53,1};
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    selection_recursion(arr, len, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* aa, int* bb)
{
    int temp;
    temp = *aa;
    *aa = *bb;
    *bb = temp;
}

void selection(int* a, int len)
{
    for ( int i = 0; i < len; i++)
    {
        int temp = i;
        for (int j = i + 1; j < len; j++)
        {
           if (a[temp] > a[j])
           {
                temp = j;
           } 
        } 
       if (temp != i)
       {
            swap(&a[i], &a[temp]);
       }
    }
}

void bubble(int* a, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

void merge(int* a, int len)
{
    // Base case
    if (len == 0 || len == 1)
    {
        return;
    }

    // Split
    int len_left = len/2;
    int len_right = len - len_left;
    int* arr_left = malloc(sizeof(int) * len_left);
    int* arr_right = malloc(sizeof(int) * len_right);

    for (int i = 0; i < len_left; i++)
    {
        arr_left[i] = a[i];
    }
    for (int i = len_left; i < len; i++)
    {
        arr_right[i - len_left] = a[i];
    }

    merge(arr_left, len_left);
    merge(arr_right, len_right);

    // Merge
    int* a_new = malloc(sizeof(int) * len);
    if (!a_new)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(arr_left);
        free(arr_right);
        exit(EXIT_FAILURE);
    }
    int left = 0;
    int right = 0;
    int count = 0;
    while (left < len_left && right < len_right)
    {
        if (arr_left[left] <= arr_right[right])
        {
            a_new[count] = arr_left[left];
            count++;
            left++;
        }
        else
        {
            a_new[count] = arr_right[right];
            count++;
            right++;
        }
    }

    while (left < len_left)
    {
        a_new[count++] = arr_left[left++];
    }

    while (right < len_right)
    {
        a_new[count++] = arr_right[right++];
    }



    // Replacing  
    for (int i = 0; i < len; i++)
    {
        a[i] = a_new[i];
    }

    free(arr_left);
    free(arr_right);
    free(a_new);
}

void selection_recursion(int* a, int len, int count)
{
    if (count == 0)
    {
        return;
    }
    int temp = len - count;

    for (int i = len - count + 1; i < len; i++)
    {
        if (a[temp] > a[i])
        {
            temp = i;
        }
    }
    if (temp != len - count)
    {
        swap(&a[len - count], &a[temp]);
    }

    return selection_recursion(a, len, count - 1);
}