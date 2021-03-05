#include <stdlib.h>
#include <stdio.h>
void add(int *array0, int size);
void print(int *array1, int size);
int swap(int *array2, int size);
void element_swap(int *a, int *b);
int check = 0; // for checking if the function element_swap is called
int main(void)
{
    int array_size;

    printf("Enter the size of array\n");

    do
    {
        scanf("%d", &array_size);

    } while(array_size <= 0 || array_size > 10);
    
   // int arr[array_size]; & allocating in heap instead of stack segement 
    int *arr = malloc(array_size * sizeof(int));

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
void element_swap(int *a, int *b)
{
        int temp = *a;
        *a = *b;
        *b = temp;
        check++;

}
int swap(int *array2, int size)
{
    int i, j, swap_var;
    // 22/02/2021 : fixing this logical bubble sort issue and adding function to swap
    /* before this correction , the code was like that :
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
    } */
    // now fixing issue :
    // adding new feature in 5/03/2021
    // the feature's goal is : optimization of runtime complexity
    // by thinking off the propability of being the array sorted
    // so i will add a global variable inside the element_swap function
    // if the function is called so there is a swap (0 for no-call)

    for(j = 0 ; j < size-1 ; j++)
    {
        for(i = 0 ; i < size -j - 1 ; i++)
        {
            if(array2[i] > array2[i+1])
            {
                element_swap(&array2[i], &array2[i+1]);
            }
        }
        if(check == 0)
        {   
            printf("your array is sorted and the algorithm complexity is : O(n)\n");
            return 0;
        }
    }
    printf("your array isn't sorted and the algorithm complexity is : O(n²)\n");
    return 1;
}

