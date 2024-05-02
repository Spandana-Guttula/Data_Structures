#include <stdio.h>
#include <string.h>

// Function to reverse a portion of a string
void reverse(char *start, char *end)
{
    while(start<end)
    {
    char temp = *start;
    *start = *end;
    *end = temp;
    start ++;
    end --;
    }
}
// Function to reverse each word in a sentence
void reverseWords(char *str, int n)
{
 int start =0;
 for (int end =0 ; end< n; end ++)
 {
    if (str[end] == ' ')
    {
        reverse(&str[start],&str[end-1]);
        printf("\n Reversed String is %d and %s",end, str);
        start = end +1;
        printf("\n Value of start is : %d",start);
    }
    
}
 reverse(&str[start],&str[n-1]);
 reverse(str,&str[n-1]);
}
int main()
{
    char str[100];
    printf("\n Enter your sentence to reverse");
    scanf("%[^\n]",str);
    int len = strlen(str);
    reverseWords(str, len);
    printf("\n Reversed String is %s",str);
    return 0;


}