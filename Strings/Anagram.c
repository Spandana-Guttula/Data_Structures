#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

// Entry point for Windows GUI application
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Your Windows GUI application code here

    // Return 0 to indicate successful execution
    return 0;
}


bool isAnagram(char *s,char *t)
{ 
    if (strlen(s)== strlen(t))
    {
    int scount[26]={0};
    int tcount[26]={0};
    int i ,j ;
    while (*s &&*t)
    {
        i = *s -'a';
        j= *t -'a';
        scount[i]++;
        tcount[j]++;
        s++;
        t++;
    }
    for (i=0;i<26;i++)
    {
    if(scount[i] != tcount[i])
        return false;
    }
    return true;
    }
    else 
    return false;
}

int main()
{
    char s[26] , t[26];
    printf("\nEnter your 1st string");
    scanf("\n%s",s);
    printf("\nEnter your 2st string");
    scanf("\n%s",t);
    if (isAnagram(s,t))
        printf("\n Anagram\n");
    else
        printf("\n Not Anagram\n");
    
    return 0;

}


