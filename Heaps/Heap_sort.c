#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x= *y;
    *y = temp;
}
void maxheapify(int heap[], int heapsize, int i )
{
    int largest = i ;
    int left = 2*i +1;
    int right = 2*i +2;
    if(left <heapsize&& heap[left]>heap[largest])
         largest= left;
    if(right <heapsize && heap[right]>heap[largest])
         largest = right;
    if(largest !=i)
    {
        swap(&heap[i],&heap[largest]);
        maxheapify(heap,heapsize, largest);
    }
}
void Heapsort(int heap[],int heapsize)
{
   //buildHeap(heap,heapsize);
   for(int i = heapsize-1; i>=1;i--)
   {
    swap(&heap[0],&heap[i]);
    maxheapify(heap,i,0);
   }
}
void buildHeap(int arr[], int n)
{

    for(int i = n/2 -1; i>= 0; i--)
    {
        maxheapify(arr,n , i);
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
    printf("\n Max heap");
    printHeap(heap,heapsize);
    Heapsort(heap,heapsize);
    printf("\n Heap Sort");
    printHeap(heap,heapsize);
    return 0;
}