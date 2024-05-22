#include<stdio.h>
#include<stdlib.h>
/* Syntax of qsort iv C 
void qsort(void* base, size_t num, size_t size, int (*compare)(const void*, const void*));

*compare: Function pointer to a comparison function that compares two elements. and const void* means read only to the data of any datatype 


returnType comparatorName(const void* a, const void* b);
if <0 means a is before b --> Asecnding order
>0 means b is before a --> descending order*/


//Comparison Function 
int compare(const void*a, const void *b)
{
    return (*(int*) a- *(int*)b);
}
int main ()
{
    int arr[]= {4,2,5,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    qsort(arr,n,sizeof(int),compare);
    printf("Sorted array :\n");
    for (int i = 0;i<n;i++)
    {
        printf("\t %d", arr[i]);
    }
    return 0;
}