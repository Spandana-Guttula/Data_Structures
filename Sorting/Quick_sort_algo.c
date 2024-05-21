#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a= *b;
    *b = temp;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int lpartition(int *arr,int low,int high)
{
    int pivot= arr[high]; //pivot
    int i = low-1; //Index of smaller element
    for(int j = low; j<= high -1; j++)
    {   
        if( arr[j]<pivot)
        {// If current element is smaller than or
        // equal to pivot
            i++; // increment index of smaller element
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}
int hpartition(int *arr,int low,int high)
{
    int pivot= arr[low]; //pivot
    int i = low-1; //Index of smaller element
    int j = high +1;

    while(1)
    {// Find leftmost element greater than
        // or equal to pivot
        do 
        {
            i++;
        }while(arr[i]<pivot);
        // Find rightmost element smaller than
        // or equal to pivot
        do{
            j--;
        }while(arr[j]>pivot);
        //if two pointer meet
        if(i>=j)
            return j;
        swap(&arr[i],&arr[j]);

    }
}

void quickSort_h(int *arr, int low, int high )
{   
    
    if (low<high)
    {
        int pi = hpartition(arr,low,high);
        quickSort_h(arr,low,pi);
        quickSort_h(arr,pi+1,high);

    }
}

void quickSort_l(int *arr, int low, int high )
{
     
    if (low<high)
    {
        int pi = lpartition(arr,low,high);
        quickSort_l(arr,low,pi-1);
        quickSort_l(arr,pi+1,high);

    }
}
void printArray(int *arr, int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("\n Enter your choice 0. Lumeto partition or 1. Hoare Partition");
    int c;
    scanf("\n %d",&c);
    if (c==0)
    {
        printf("\n Excecuting Lumeto method");
        quickSort_l(arr, 0, n-1);
    }
    else
    {
        printf("\n Excecuting Hoare method");
        quickSort_h(arr, 0, n-1);
    }
    printf("\n Sorted array: \n");
    printArray(arr, n);
    return 0;
}