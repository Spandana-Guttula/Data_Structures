#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"

struct hashentry
{
    int key;
    int count;
    UT_hash_handle hh;
};

int countDistinct(int* arr1, int size1,int* arr2, int size2) {
    struct hashentry *hashtable= NULL, *entry, *temp;

    for (int i=0; i<size1; i++)
    {
        HASH_FIND_INT(hashtable,&arr1[i],entry);
        if(entry == NULL)
        {
            entry = (struct hashentry*)malloc(sizeof(struct hashentry));
            entry->key = arr1[i];
            entry->count = 1;
            HASH_ADD_INT(hashtable, key, entry);

        }
        else 
            entry->count++;
    }
    for (int i=0; i<size2; i++)
    {
        HASH_FIND_INT(hashtable,&arr2[i],entry);
        if(entry == NULL)
        {
            entry = (struct hashentry*)malloc(sizeof(struct hashentry));
            entry->key = arr2[i];
            entry->count = 1;
            HASH_ADD_INT(hashtable, key, entry);

        }
        else 
            entry->count++;
    }
    int res=1;
    HASH_ITER(hh,hashtable,entry,temp)
    {
        if(entry->count ==1)
        {
            res++;
        }
    }
    // Free the hash table
    HASH_ITER(hh, hashtable, entry, temp) {
        HASH_DEL(hashtable, entry);
        free(entry);
    }

    return res;
  
}

int main() {
    int arr1[] = {3,3,3,3};
    int arr2[] = { 3,3};
  
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int distinctCount = countDistinct(arr1, size1,arr2,size2);
    printf("Number of distinct elements: %d\n", distinctCount);

    return 0;
}