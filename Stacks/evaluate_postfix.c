#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include<string.h>
#include <limits.h>
#include<ctype.h>

struct stack {
    int top;
    unsigned size;
    int *array;
};
struct stack *CreateStack(unsigned size)
{
    struct stack *S = (struct stack*)malloc(sizeof(struct stack));
    S->top =-1;
    S->size= size;
    S->array = (int*)malloc(sizeof (int));
    return S;
}
int StackEmpty(struct stack *S)
{
    return (S->top == -1);
   
}
void push(struct stack *S, int x)
{
    
      
        S->array[++S->top] = x;
    
    //printf("%d pushed to stack\n", x);
}
int pop(struct stack *S)
{
   if(S->top == -1)
        return INT_MIN;
    else
    {
        int popped_number = S->array[S->top];
        S->top = S->top -1;
        return popped_number;
    }
    /*if (!StackEmpty(S))
        return S->array[S->top--];
    return '$'; */

}
// The main function that returns value
// of a given postfix expression
int evaluate_postfix(char* exp)
{
    struct stack *S1= CreateStack(strlen(exp));
    
    // Scan all characters one by one
    for (int i=0; i<strlen(exp);i++)
    {
        // if the character is blank space then continue
        if(exp[i]==' ')
            continue;
        // If the scanned character is an
        // operand (number here),extract the full number
        // Push it to the stack.
        else if (isdigit(exp[i]))
        {
            int num =0;
            // extract full number
            while(isdigit(exp[i]))
            {
                // this step is necessary to convert char to int 
                num = num*10 +((int)(exp[i]-'0'));
                i++;
            }
            i-- ;

            push(S1,num);
        }
        // If the scanned character is an operator, pop two
        // elements from stack apply the operator
        else
        {
            int val1= pop(S1);
            int val2= pop(S1);

            switch(exp[i])
            {
                case '+':
                    push(S1,val2 + val1);
                    break;
                case '-':
                    push(S1,val2 - val1);
                    break;
                case '*':
                    push(S1,val2 * val1);
                    break;
                case '/':
                    push(S1,val2/val1);
                    break;

            }
        }
    }
    return pop(S1);
}
// Driver program to test above functions
int main()
{
    char exp[] = "100 200 + 2 / 5 * 7 +";
   
    // Function call
    printf("%d", evaluate_postfix(exp));
    return 0;

}