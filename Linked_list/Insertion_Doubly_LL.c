#include<stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
void insert_at_beginning(struct Node ** head_ref, int new_data)
{   
     /* 1. allocate node */
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    /* 2.Insert the date value*/
    new_node->data = new_data;
    /*3.Make the new node point to current head*/
    new_node->next = (*head_ref);
    new_node->prev= NULL;
    /*4.Change prev of head node to new node*/
    if (*head_ref != NULL)
        (*head_ref)->prev = new_node;
    /*5. Update the head to point to the new node*/
    (*head_ref) = new_node;
}
void insert_after(struct Node *prev_node, int new_data)
 {
    /*1 check if the given prev_node is NULL*/
    if(prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    } 
    /*2. allocate a new node*/
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    /*3. put in the data*/
    new_node->data = new_data;
    /*4. Make next to the new node as next of prev_node*/
    new_node->next = prev_node->next;
    /*5. move the next of prev_node to new node */
    prev_node->next = new_node;

    new_node->prev = prev_node; 
 }
 // ** pointer for  allowing modifications to be made directly to the original head pointer passed from the calling function.
 void insert_at_end(struct Node **head_ref, int new_data)
 {
  /* 1. allocate node */
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
   /* 2. put in the data */ 
    new_node->data = new_data;
  /* 3. This new node is going to be the last node, so
    make next of it as NULL*/
    new_node->next = NULL;
    /* 4. If the Linked List is empty, then make the new
    * node as head */
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
  /*5.traverse till last*/
  struct Node *last= *head_ref;
 
  
  /* 6. Else traverse till the last node */
  while(last->next != NULL)
  {
    last = last->next;
  }
  /* 7.Change the next pointer to the last node to point to new node*/
  last->next= new_node;
  new_node->prev = last;

 }
void printList(struct Node* node)
{
    while (node != NULL) {
        printf(" %d", node->data);
        node = node->next;
    }
}
 int main()
 {
    //start with an empty List
    struct Node *head = NULL;

    insert_at_beginning(&head,100);
    insert_at_beginning(&head,80);
    insert_at_beginning(&head,70);
    insert_at_beginning(&head,60);
    insert_at_beginning(&head,40);
    printf("\n Created Linked list after inserting at beginning: ");
    printList(head);
    insert_at_end(&head,110);
    insert_at_end(&head,120);
    printf("\n Created Linked list after inserting at end: ");
    printList(head);
    insert_after(head->next->next->next->next, 105);
    printf("\n After inserting 105 after 100: ");
    printList(head);
 }
 