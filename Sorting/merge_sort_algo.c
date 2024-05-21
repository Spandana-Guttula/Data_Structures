#include<stdio.h>
void merge(int *arr, int l, int m, int r)
{
    int n1 = m - l + 1; // Size of the left subarray
    int n2 = r - m;     // Size of the right subarray
    // Temporary arrays to hold the subarrays
    int left[n1], right[n2];
    // Copy data to temporary arrays left[] and right[]
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[], if any
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[], if any
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
   
}
void merge_sort(int *arr,int l, int r)
{
 if(r>l)
 {
    int m = l+(r-l)/2;
    merge_sort(arr,l,m);
    merge_sort(arr,m+1,r);
    merge(arr,l,m,r);
 }

}

int main ()
{
    int arr[] = {10,5,30,15,7};
   
    int r = sizeof(arr) / sizeof(arr[0]);
    
    printf("Given array is: ");
    for (int i = 0; i < r; i++)
        printf("%d ", arr[i]);
    printf("\n");

    merge_sort(arr, 0,r-1);
    printf("Sorted array is: ");
    for (int i = 0; i < r; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}