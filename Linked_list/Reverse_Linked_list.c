#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data ;
    struct Node *next;
};
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;

}
void reverse_ll(struct Node **head_ref)
{
    struct Node * prev = NULL;
    struct Node *current = *head_ref;
    struct Node * next = NULL;
    while (current!= NULL)
    {
        //store next
        next = current->next;
        //Reverse current node 
        current->next = prev;
        // Move pointers one position ahead
        prev = current;
        current = next ;

    }
    *head_ref = prev;
}

void printList( struct Node *node)
{
  while (node != NULL) {
        printf(" %d", node->data);
        node = node->next;
    }
}
int main ()
{
    struct Node *head = NULL;

    push(&head,50);
    push(&head,40);
    push(&head,30);
    push(&head,20);
    push(&head,10);

    printf("Original Linked List \n");
    printList(head);
    reverse_ll(&head);
    printf("\n Reversed Linked List \n");
    printList(head);
    return 0;
 
}