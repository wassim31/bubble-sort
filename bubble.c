#include <stdlib.h>
#include <stdio.h>
void add(int *array0, int size);
void print(int *array1, int size);
void swap(int *array2, int size);
int main(void)
{
    int array_size;
    printf("Enter the size of array\n");
    do
    {
        scanf("%d", &array_size);
    } while(array_size < 0 || array_size > 10);
    int arr[array_size];
    add(arr, array_size);
    print(arr, array_size);
    swap(arr, array_size);
    printf("New sorted array : \n");
    print(arr, array_size);
    return 0;
}
void add(int *array0, int size)
{
    printf("add %d values to your array:\n", size);
    int i;
    for(i = 0 ; i < size ; i++)
    {
        scanf("%d", &array0[i]);
    }
}
void print(int *array1, int size)
{
    int i;
    for(i = 0 ; i < size ; i++)
    {
        printf("%d ", array1[i]);
    }
    printf("\n");
}
void swap(int *array2, int size)
{
    int i, j, temp;
    for(j = 0 ; j < size-1 ; j++)
    {
        for(i = 0 ; i < size-1 ; i++)
        {
            if(array2[i] > array2[i+1])
            {
                temp = array2[i];
                array2[i] = array2[i+1];
                array2[i+1] = temp;
            }
        }
    }
}

