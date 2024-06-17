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
int extractmax(int heap[],int *heapsize)
{
    // Check if heap is empty
    if (*heapsize == 0) {
    printf("Heap underflow\n");
    return -1; // Or any error value
  }
    // Store the minimum element (root)
    int max = heap[0];
    // Replace root with the last element
    heap[0]= heap[*heapsize -1];
    // Decrement heap size
    (*heapsize)--;
    // Heapify the root (maintain min-heap property)
    maxheapify(heap, *heapsize, 0);
    return max;
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
    printf("\n Min heap");
    printHeap(heap,heapsize);
    printf("Extract minimum = %d",extractmax(heap,&heapsize));
    printf("\n New Min heap");
    printHeap(heap,heapsize);
    return 0;
}