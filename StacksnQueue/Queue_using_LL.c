#include<limits.h>
#include<stdio.h>
#include<stdlib.h>

struct QNode{
    int key;
    struct QNode *next;
};

struct Queue{
    struct QNode *front,*rear;
   
};

struct QNode *newNode(int k)
{
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;

}
//create Queue

struct Queue *create_Queue()
{
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front= queue->rear  = NULL;
    return queue;

}


void enQueue(struct Queue *queue, int item)
{

  struct QNode *temp = newNode(item);
  if (queue->front==NULL)
  {
    queue->front = queue->rear = temp;
    printf("\nEnqueued to queue: %d", item);
     return;
  }
  
// Add the new node at the end of queue and change rear
  queue->rear->next = temp;
  queue->rear = temp;
  
 
  printf("\n Enqued to queue %d", item);
}
void  deQueue(struct Queue *queue)
{
    if(queue->front ==NULL)
    {
        return ;
    }
    struct QNode *temp = queue->front;

    queue->front =queue->front->next;
    if(queue->front==NULL)  
        queue->rear = NULL;
    printf("\nDequeued from queue: %d", temp->key);
    free (temp) ;

}// Driver code
int main()
{
    struct Queue* q = create_Queue();
    enQueue(q, 10);
    enQueue(q, 20);
    deQueue(q);
    deQueue(q);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);
    deQueue(q);
    printf("\n Queue Front : %d \n", ((q->front != NULL) ? (q->front)->key : -1));
    printf("Queue Rear : %d", ((q->rear != NULL) ? (q->rear)->key : -1));
    return 0;
}
