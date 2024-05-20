/* Two pointer approach */
#include <stdio.h>
void merge(int *a, int *b, int m, int n)
{
    int i = 0;
    int j =0;
    while( i<m &&j<n)
    {
        if(a[i]<=b[j])
         {
             printf("\t %d",a[i]);
            i++;
         }  
        else
          { 
            printf("\t %d",b[j]); 
            j++;
          }
    }
    while(i<m)
     {    printf("\t %d",a[i]);
            i++;
     }
    while(j<n)
    {
         printf("\t %d",b[j]);
            j++;
    }
}

int main ()
{
    int a[] = {10,20,50};
    int b[] = {5,50,50};
    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);
    merge(a, b, m, n);
    return 0;
}