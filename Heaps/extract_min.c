#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x= *y;
    *y = temp;
}
void minheapify(int heap[], int heapsize, int i )
{
    int smallest = i ;
    int left = 2*i +1;
    int right = 2*i +2;
    if(left <heapsize&& heap[left]<heap[smallest])
         smallest = left;
    if(right <heapsize && heap[right]<heap[smallest])
         smallest = right;
    if(smallest !=i)
    {
        swap(&heap[i],&heap[smallest]);
        minheapify(heap,heapsize, smallest);
    }
}
int extractmin(int heap[],int *heapsize)
{
    int min = heap[0];
    heap[0]= heap[*heapsize -1];
    (*heapsize)--;
    minheapify(heap, *heapsize, 0);
    return min;
}
void buildHeap(int arr[], int n)
{

    for(int i = n/2 -1; i>= 0; i--)
    {
        minheapify(arr,n , i);
    }
}

void printHeap(int arr[],int n)
{
    for(int i =0; i<n; i++)
    {
        printf("\t %d",arr[i]);
    }
    printf("\n");
}

int main ()
{
    int heap[]={12,13,15,7,6,8};
    int heapsize= sizeof(heap)/sizeof(heap[0]);
    printf("\n Original heap");
    printHeap(heap,heapsize);
    buildHeap(heap,heapsize);
    printf("\n Min heap");
    printHeap(heap,heapsize);
    printf("Extract minimum = %d",extractmin(heap,&heapsize));
    printf("\n New Min heap");
    printHeap(heap,heapsize);
    return 0;
}