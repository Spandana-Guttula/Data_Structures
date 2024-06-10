#include<stdio.h>
#include<stdlib.h>
#include "uthash.h"

struct hashentry{
    int key;
    int count ;
    UT_hash_handle hh;
};

void calculateFrequencies(int* arr, int size)
{
  struct hashentry  *hashtable= NULL, *entry,*temp;
  for(int i =0; i<size;i++)
  {
    HASH_FIND_INT(hashtable,&arr[i],entry);
    if (entry ==NULL)
        {
            entry= (struct hashentry *)malloc(sizeof(struct hashentry));
            entry->key = arr[i];
            entry->count = 1;
            HASH_ADD_INT(hashtable,key,entry);
        }
        else
            entry->count++;
  }
    HASH_ITER(hh,hashtable,entry,temp)
   {
        printf("Element %d :%d times\n",entry->key,entry->count);
  }
  HASH_ITER(hh,hashtable,entry,temp)
   {
        HASH_DEL(hashtable,entry);
        free(entry);
  }
  

}



int main()
{
    int arr[] = {10, 20, 20, 10, 30, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    calculateFrequencies(arr, size);

    return 0;

}
