#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

struct Queue{
    int front,rear,size;
    unsigned capacity;
    int *array;
};
//create Queue

struct Queue *create_Queue(unsigned capacity)
{
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size= 0;
    queue->rear = capacity -1;
    queue->array = (int*)malloc(queue->capacity*sizeof(int));
    return queue;

}

int IsFull(struct Queue *queue)
{
    return (queue->size== queue->capacity);
}
int IsEmpty(struct Queue *queue)
{
    return (queue->size==0);
}
void enqueue(struct Queue *queue, int item)
{
  if (IsFull(queue))
    return;
  queue->rear = (queue->rear +1)%queue->capacity;
  queue->array[queue->rear]= item;
  queue->size = queue->size +1;
  printf("\n Enqued to queue %d", item);
}
int  dequeue(struct Queue *queue)
{
    if(IsEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front +1)%queue->capacity;
    queue->size = queue->size -1;
    return item;

}
// Driver program to test above functions./
int main()
{
    struct Queue* queue = create_Queue(1000);
 
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
 
    printf("\n %d dequeued from queue\n\n",dequeue(queue));
 
    //printf("Front item is %d\n", front(queue));
    //printf("Rear item is %d\n", rear(queue));
    printf("Front item is %d\n", queue->array[queue->front]);
    printf("Rear item is %d\n", queue->array[queue->rear]);
 
    return 0;
}
