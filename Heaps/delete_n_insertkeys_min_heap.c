#include<stdio.h>
#include <stdlib.h>

void swap(int *x, int*y)
{
    int temp = *y;
    *y= *x;
    *x= temp;
}
void minHeapify(int heap[], int heapsize,int i)
{
    int smallest = i;
    int left = 2*i +1;
    int right = 2*i+2;

    if(left < heapsize && heap[left]<heap[smallest])
    {
        smallest = left;
    }
    if(right <heapsize && heap[right]<heap[smallest])
    {
        smallest = right;
    }
    if(smallest != i)
    {
        swap(&heap[i],&heap[smallest]);
        minHeapify(heap,heapsize,smallest);
    }
}


void deletekey(int heap[],int *heapsize, int key)
{
    int i;
    for(i=0;i<*heapsize;i++)
    {
        if(heap[i]==key)
            break;
        
    }
    if(i ==*heapsize)
    {
        printf("key not found in the heap\n");
        return;
    }
    //Replace the key to be deleted with the last element
    heap[i]= heap[*heapsize -1];
    (*heapsize)--;
    //heapify the heap after deletion
    minHeapify(heap,*heapsize,i);
}
void insertkey(int heap[],int *heapsize, int key)
{
    int new_index = *heapsize;
    heap[new_index]= key;
    (*heapsize)++;
     
      // Fix the min-heap property if it is violated
    int parent = (new_index -1)/2;
    while(new_index>0 &&heap[parent]>heap[new_index])
    {
        swap(&heap[parent],&heap[new_index]);
        new_index= parent;
        parent = (new_index-1)/2;
    }
}

void buildMinHeap(int arr[],int n)
{
    for(int i = n/2-1;i>=0;i--)
    {
        minHeapify(arr,n,i);
    }
}

void printHeap(int heap[], int heapsize)
{
    printf("Heap: ");
    for(int i =0; i<heapsize;i++)
    {
        printf("\t %d",heap[i]);
    }
    printf("\n");
}

int main()
{
    int heap[]={12,11,13,5,6,7};
    int heapsize= sizeof(heap)/sizeof(heap[0]);
    int key =13;
    printf("\n original");
    printHeap(heap,heapsize);
    buildMinHeap(heap,heapsize);
    printf("\n Min Heap");
    printHeap(heap,heapsize);
    deletekey(heap,&heapsize, key);
    printf("\n After Deletion of root (%d):\n",key);
    printHeap(heap,heapsize);
    int key_add =15;
    insertkey(heap,&heapsize,key_add);
    printf("\n After Inserting of root (%d):\n",key_add);
    printHeap(heap,heapsize);

    return 0;

}