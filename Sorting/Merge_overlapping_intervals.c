#include<stdio.h>
#include<stdlib.h>
// Define max and min macros
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
// Define the struct point
struct range
{
    int start,end;
};

// Comparison function for qsort
int compare(const void *a, const void *b)
{
    struct range *pointA = (struct range *)a;
    struct range *pointB = (struct range *)b;
    return (pointA->start - pointB->start);
}

int main()
{
  struct range arr[]= {{5,10},{3,15},{18,30},{2,7}};
 
  int n = sizeof(arr)/sizeof(arr[0]);
  // Sort the array using qsort
  qsort(arr,n,sizeof(struct range),compare);
  int res=0;
  for (int i =1; i<n;i++)
{
    if(arr[res].end >=arr[i].start)
    {
        arr[res].end = max(arr[res].end, arr[i].end);
        arr[res].start = min(arr[res].start, arr[i].start);
    }
    else
    {
        res++;
        arr[res]=arr[i];
    }
}
    /* This will print entire merged interval + extra elements
    **************************************
    Output will be
    **********************************
    Merged Intervals :
         2, 15   18, 30  5, 10   18, 30
    **************************************
    (so take care of i which should go till res not n)     
    printf("Merged Intervals :\n");
    for (int i = 0;i<n;i++)
    {
        printf("\t %d, %d", arr[i].start, arr[i].end);
    }
    */
    

   printf("Merged Intervals :\n");
    for (int i = 0;i<=res;i++)
    {
        printf("\t %d, %d", arr[i].start, arr[i].end);
    }
    
    return 0;
}