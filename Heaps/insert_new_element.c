#include<stdio.h>
//swap function
void swap(int *x, int *y)
{
    int temp = *x;
    *x= *y;
    *y = temp;
}

/*void buildMaxHeap(int arr[],int n)
{
    for(int i = n/2-1;i>=0;i--)
    {
        maxHeapify(arr,n,i);
    }
}
void maxHeapify(int *arr,int n, int i )
{
    int largest = i;
    int left = 2*i +1;
    int right = 2*i+ 2;

    if(left <n &&arr[left]>arr[largest])
    {
        largest = left;
    }
    if(right <n &&arr[right]>arr[largest])
    {
        largest = right;
    }
    if(largest != i)
    {
        swap(&arr[i],&arr[largest]);
        maxHeapify(arr, n,largest);
    }
} */
void insertMaxHeap(int arr[], int *n, int key)
{
     *n = *n+1;
     int i = *n-1;
     arr[i]= key;
     // fix the max heap property if it is voilated
     while(i!=0 &&(arr[(i-1)/2]) <arr[i])
     {
        swap(&arr[i],&arr[(i-1)/2]);
        i = (i-1)/2;
     }
}
void printHeap(int *arr, int n)
{
    for(int i =0; i<n; i++)
    {
        printf("\t %d",arr[i]);
    
    }
    printf("\n");

}
int main()
{
    int arr[20] ={10, 5, 3, 2, 4};
    int n =5;
   // buildmaxHeap(arr,n);
    //Print initial Heap
    printf("\n Initail Max Heap");
    printHeap(arr,n);

    //Insert a new element
    int key = 15;
    insertMaxHeap(arr,&n,key);

    //Print heap after insertion
    printf("\n Max Heap after insertion of %d\n",key);
    printHeap(arr,n);

    return 0;


}