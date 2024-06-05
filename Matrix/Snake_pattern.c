
#include<stdio.h>


void printMatrixInSnakePattern(int matrix[][4], int rows, int cols) 
{
    for(int i =0; i<rows;i++)
    {
        if(i%2==0)
        {
            for(int j =0; j<cols;j++)
                printf("\t %d",matrix[i][j]);
        }
        else
            for(int j= cols-1;j>=0;j--)
                printf("\t %d",matrix[i][j]);
     // Move to the next line after each row  
    printf("\n");             
    }
}

// Driver code
int main()
{
    int matrix[4][4] = { { 10, 20, 30, 40 },
                      { 15, 25, 35, 45 },
                      { 27, 29, 37, 48 },
                      { 32, 33, 39, 50 } };
    int rows = 4;  
    int cols = 4;  
    printf("Matrix in Snake Pattern:\n");  
    printMatrixInSnakePattern(matrix, rows, cols);  
    return 0;
}