#include<stdio.h>
#include<stdlib.h>
#include"uthash.h"

typedef struct 
{
    int key;
    int index;
    UT_hash_handle hh;
}hashentry;

int twosum(int *arr, int size, int target)
{
    hashentry *hashtable= NULL, *entry, *temp;
    for(int i = 0; i<size;i++)
  {
    int search = target - arr[i];
    //HASH_FIND_INT(hashtable,&search,entry);
    HASH_FIND_INT(hashtable, &search, entry);
    if(entry== NULL)
    {
      entry = (hashentry *)malloc(sizeof(hashentry));
      entry->key = arr[i];
      entry->index = i;  // Store the index
      HASH_ADD_INT(hashtable,key,entry);
    }
    else 
    {
        printf("Pair found: [%d,%d]\n", entry->index, i);
    }
  }
 // Free the remaining hash table entries
    HASH_ITER(hh, hashtable, entry, temp) {
        HASH_DEL(hashtable, entry);
        free(entry);
    }
}
int main()
{
    int arr[]= {2,7,11,15};
    int target = 9;
    int size = sizeof(arr)/sizeof(arr[0]);
    twosum(arr,size,target);
}