#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
struct stack
{
    unsigned size;
    int top;
    int *array;
};

struct stack* createStack( unsigned size)
{
    struct stack *S = (struct stack*)malloc(sizeof (struct stack));
    S->size = size;
    S->top= -1;
    S->array = (int*)malloc(S->size *sizeof(int));
    return S;

}

bool StackEmpty(struct stack* S)
{
    if (S->top == -1)          
        return true;
    else 
        return false;
}
void push(struct stack *S , int x)
{
    if(S->top == S->size -1)
        return;
    else
    {
        S->top = S->top +1;
        S->array[S->top] = x;
    }
    printf("%d pushed to stack\n", x);
}
int pop(struct stack *S)
{
    if(StackEmpty(S))
        return INT_MIN;
    else
    {
        int popped_element = S->array[S->top];
        S->top = S->top -1;
        return popped_element;
    }
}
int main()
{
    struct stack *S = createStack(10);
    push(S,10);
    push(S,20);
    push(S,30);
    push(S,40);
    push(S,50);
    printf("%d popped from stack\n",pop(S));
    printf("%d popped from stack\n",pop(S));
     printf("%d popped from stack\n",pop(S));
    return 0;
}