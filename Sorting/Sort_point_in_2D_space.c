#include<stdio.h>
#include<stdlib.h>
// Define the struct point
struct point
{
    int x,y;
};

// Comparison function for qsort
int compare(const void *a, const void *b)
{
    struct point *pointA = (struct point *)a;
    struct point *pointB = (struct point *)b;
    return (pointA->x - pointB->x);
}

int main()
{
  struct point arr[]= {{3,10},{2,8},{5,4}};
 
  int n = sizeof(arr)/sizeof(arr[0]);
  // Sort the array using qsort
  qsort(arr,n,sizeof(struct point),compare);
   printf("Sorted array :\n");
    for (int i = 0;i<n;i++)
    {
        printf("\t %d, %d", arr[i].x, arr[i].y);
    }
    return 0;
}