#include<stdio.h>
#include<stdbool.h>
#include"uthash.h"

typedef struct 
{
    int key;
    UT_hash_handle hh;
} hashentry;
 
 void intersection(int *arr1,int size1, int *arr2,int size2)
 {
    hashentry *hashtable = NULL, *entry, *temp;
     // Add elements of arr2 to the hash table
   for(int i =0;i<size2;i++)
   {
     HASH_FIND_INT(hashtable, &arr2[i], entry);
     if (entry == NULL) {
        entry = (hashentry*)malloc(sizeof(hashentry));
        entry->key = arr2[i];
        HASH_ADD_INT(hashtable,key,entry);
   }
   }
   // Check elements of arr1 for intersection
   printf("Intersection: ");
   for (int i =0;i<size1;i++)
   {
    HASH_FIND_INT(hashtable,&arr1[i],entry);
    if (entry != NULL) 
    //if(entry->key ==arr1[i])
    {
            printf("%d ", arr1[i]);
            // Remove the element to prevent duplicates in the intersection result
            HASH_DEL(hashtable, entry);
            free(entry);
        }
    }
    printf("\n");
// Free the remaining hash table entries
    HASH_ITER(hh, hashtable, entry, temp) {
        HASH_DEL(hashtable, entry);
        free(entry);
    }
}
void union_of_arrays(int *arr1,int size1, int *arr2, int size2)
{
    hashentry *hashtable = NULL, *entry, *temp;
    for(int i =0 ; i<size1;i ++)
    {
        HASH_FIND_INT(hashtable,&arr1[i],entry);
        if(entry ==NULL)
        {
            entry = (hashentry*)malloc(sizeof(hashentry));
            entry->key = arr1[i];
            HASH_ADD_INT(hashtable,key,entry);

        }
    }
    printf("Union:");
    for(int i =0;i<size2;i++)
    {
        HASH_FIND_INT(hashtable,&arr2[i],entry);
        if(entry==NULL)
        {
            entry = (hashentry*)malloc(sizeof(hashentry));
            entry->key = arr2[i];
            HASH_ADD_INT(hashtable,key,entry);
             
        }
    }
  
    // Print the Union
    HASH_ITER(hh, hashtable, entry, temp) {
        printf("%d\t", entry->key);
    }
// Free the remaining hash table entries
    HASH_ITER(hh, hashtable, entry, temp) {
        HASH_DEL(hashtable, entry);
        free(entry);
    }

}

int main()
{
    int arr1[]= {10,20,30};
    int arr2[]= {30,10,40,60};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    intersection(arr1,size1,arr2,size2);
    union_of_arrays(arr1,size1,arr2,size2);
    return 0;
}