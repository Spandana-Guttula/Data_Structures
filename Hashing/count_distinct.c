#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"

struct hashentry
{
    int key;
    int count;
    UT_hash_handle hh;
};

int countDistinct(int* arr, int size) {
    struct hashentry *hashtable= NULL, *entry, *temp;

    for (int i=0; i<size; i++)
    {
        HASH_FIND_INT(hashtable,&arr[i],entry);
        if(entry == NULL)
        {
            entry = (struct hashentry*)malloc(sizeof(struct hashentry));
            entry->key = arr[i];
            entry->count = 1;
            HASH_ADD_INT(hashtable, key, entry);

        }
        else 
            entry->count++;
    }
    int res=0;
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
    int arr[] = {1, 2, 3, 4, 5, 1, 2, 3};
  
    int size = sizeof(arr) / sizeof(arr[0]);

    int distinctCount = countDistinct(arr, size);
    printf("Number of distinct elements: %d\n", distinctCount);

    return 0;
}