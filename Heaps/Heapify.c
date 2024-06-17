#include<stdio.h>

void swap(int *x, int *y)
{
    int temp = *y;
    *y = *x;
    *x = temp;
}

void minHeapify(int arr[],int n ,int i)
{
    int smallest = i;
    int left = 2*i +1;
    int right = 2*i +2;

    if(left <n &&arr[left]<arr[smallest])
    {
        smallest = left ;
    }
    if(right <n && arr[right]<arr[smallest])
    {
        smallest =right;
    }
    if(smallest != i)
    {
        swap(&arr[i],&arr[smallest]);
        minHeapify(arr,n,smallest);
    }
}
void maxHeapify(int arr[],int n ,int i)
{
    int largest = i;
    int left = 2*i +1;
    int right = 2*i +2;

    if(left <n &&arr[left]>arr[largest])
    {
        largest = left ;
    }
    if(right <n && arr[right]>arr[largest])
    {
        largest =right;
    }
    if(largest != i)
    {
        swap(&arr[i],&arr[largest]);
        maxHeapify(arr,n,largest);
    }
}
void buildMinHeap(int arr[],int n)
{
    for(int i = n/2-1;i>=0;i--)
    {
        minHeapify(arr,n,i);
    }
}

void buildMaxHeap(int arr[],int n)
{
    for(int i = n/2-1;i>=0;i--)
    {
        maxHeapify(arr,n,i);
    }
}

void printArray(int arr[],int n)
{
    for(int i =0; i<n;i++)
    {
        printf("\t %d",arr[i]);
    }
    printf("\n");
}


int main()
{
    int arr[]={4,10,3,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    buildMinHeap(arr,n);
    printf("Min Heap array: \n");
    printArray(arr,n);
    buildMaxHeap(arr,n);
    printf("Max Heap array: \n");
    printArray(arr,n);
    return 0;
}
