#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node 
{
    int data;
    struct Node *next;
};

void push (struct Node **head_ref, int new_data)
{
    /* allocate node */
    struct Node *new_node = (struct Node*)malloc(sizeof (struct Node));
     /* put in the key  */
    new_node->data = new_data;
    /* link the old list of the new node */
    new_node->next = *head_ref;
     /* move the head to point to the new node */
    (*head_ref) = new_node;

}
bool search(struct Node *head, int x)
{
  struct Node *current = head;
  while(current!= NULL)
  {
    if(current->data==x)
        return true;
    current= current->next ;
  }
  return false;
}
int main ()
{
    struct Node *head = NULL;
    int x=60;
    /*Use Push to create a linked list */
    push(&head,50);
    push(&head,40);
    push(&head,30);
    push(&head,20);
    push(&head,10);

    //Function call for search
    search(head,x)?printf("FOUND"):printf("NOT_FOUND");
    return 0;


}