#include<stdio.h>

int swap(int *a, int *b)
{
    int c = *a;
    *a=*b;
    *b=c;
   
}

void transpose(int matrix[][4], int rows, int cols)
{
    for (int i =0 ; i< rows;i++)
    {
        for (int j = i+1; j< cols;j++)
        {
            swap(&matrix[i][j],&matrix[j][i]);
           
        }
}}

// Function to print a matrix
void printMatrix(int matrix[4][4], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    int matrix[4][4] = { { 10, 20, 30, 40 },
                      { 15, 25, 35, 45 },
                      { 27, 29, 37, 48 },
                      { 32, 33, 39, 50 } };
    int rows = 4;  
    int cols = 4;  
    printf("Original matrix:\n");
    printMatrix(matrix, rows, cols);

    printf("Transpose of matrix is:\n");
    transpose(matrix, rows, cols);
    printMatrix(matrix, rows, cols); 
    return 0;
}