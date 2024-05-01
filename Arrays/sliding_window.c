/* Find the maximum sum of k consecutive elements*/
#include <stdio.h>

int max(int a,int b)
{
    return (a>b)?a:b;
}
int maxSum(int arr[], int n , int k )
{
    int current = 0;
    for (int i =0; i<k ; i++)
        current += arr[i];
    int result = current;
    for(int i = k ; i< n; i++)
    {
        current= current +arr[i] - arr[i-k];
        result = max(result,current);
    }
    return result; 
}

int main()
{
    int arr[] ={5,-10,6,90,3};
    int k =2;
    printf("Maximum sum of %d consecutive elements:%d\n",k,maxSum(arr,5,2));
    return 0;
}