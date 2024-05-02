#include <stdio.h>
#include <string.h>
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Your code here
    return 0;
}
int IsPalindrome(char *str)
{
    int begin =0;
    int end = strlen(str) -1;
    while(begin <end)
    {
        if(str[begin] != str[end])
            return 0;
        begin ++;
        end -- ;
    }
    return 1;
}

int main()
{
    char str[20];
    printf("\n Enter the string to check if it is pallindrome or not");
    scanf("\n %s",str);
    
    if (IsPalindrome(str)==1)
        printf("\n Pallindrome");
    else
        printf("\n Not Pallindrome");
    
    return 0;
}