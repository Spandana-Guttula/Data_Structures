#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void push(struct Node** head_ref,int new_data)
{
    struct Node* new_node =(struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next= *head_ref;
    *head_ref = new_node;
}

int main()
{
    struct Node* head = NULL;
    push(&head,10);
    push(&head,20);
    push(&head,10);
    push(&head,30);

//Print the Link List
struct Node* temp = head;
while( temp!= NULL)
{
    printf("\n  %d",temp->data);
    temp = temp->next;
}
}