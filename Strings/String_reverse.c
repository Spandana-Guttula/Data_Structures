#include <stdio.h>
#include <string.h>


void string_rev(char* str)
{
    int len = strlen(str);
    char *start = str ;
    char *end = str + len -1;
    while (start<end)
    {
        char temp = *start;
        *start = *end ;
        *end = temp;
        start ++;
        end--;
    }

}
int main ()
{
    char str[] = "Spandana";
    printf("\n Enter your Choice 1. Library function  2. using 2 pointers ");
    char c ;
    scanf ("%c", &c);

    //reverse string
    switch (c)
    {
    case '1' :
         printf("\n Reversed String using library: %s ",strrev(str));
         break ;
    case '2':
         string_rev(str);
         printf("\n Reversed String using 2 pointers : %s ",str);
         break; 
    default : 
         printf("\n Didnt reverse");
         break; 
    }
        return 0; 
}