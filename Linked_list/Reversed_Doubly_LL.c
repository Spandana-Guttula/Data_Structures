#include <stdio.h>
#include <stdlib.h>

struct Node {
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
void reverse_doubly_Linkedlist(struct Node **head)
{
   
   struct Node *temp =NULL;
   struct Node *current = *head;
   while (current != NULL)
   {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; 
   }
   if (temp != NULL) {
        *head = temp->prev;
    }

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
    printf("\n Created Linked list after reversing: ");
    reverse_doubly_Linkedlist(&head);
    printList(head);
    return 0;
 }