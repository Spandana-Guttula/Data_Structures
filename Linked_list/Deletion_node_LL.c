#include <stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*head = NULL;

void push(struct Node **head, int new_data)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head;
    (*head) = new_node ;

}
void delete_from_starting(struct Node **head)
{
    struct Node *temp = *head;
    *head =temp->next ;
    free(temp); 
}
void delete_from_N_pos( int pos)
{
    struct Node *temp = head;
    int i ;
    if(pos ==0)
    {
        head= temp->next;
        free(temp);
    }

    else
    {
     for( i =0; i< pos -1 ; i++)
        temp= temp->next;
     struct Node *del = temp->next ;
     temp->next = temp->next->next;
     del->next = NULL;
     free(del);
     }
}
void delete_from_end(struct Node *head)
{
    struct Node *end = head;
    struct Node *prev = NULL;
    while(end->next)
    {
        prev = end;
        end = end->next;
    }
    prev->next = NULL; 
    free(end);



}
void printList (struct Node *node)
{
    while (node != NULL) {
        printf(" %d", node->data);
        node = node->next;
    }
}
int main ()
{
    

    push(&head,80);
    push(&head,70);
    push(&head,60);
    push(&head,50);
    push(&head,40);
    push(&head,30);
    push(&head,20);
    push(&head,10);
    printf("\n Orginial list ");
    printList(head);
    delete_from_starting(&head);
    printf("\n List after deletion from starting");
    printList(head);
    delete_from_end(head);
    printf("\n List after deletion from end");
    printList(head);
    delete_from_N_pos(3);
    printf("\n List after deletion  4th node");
    printList(head);


}
