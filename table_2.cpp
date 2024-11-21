
#include <cstdlib>   // malloc, free, atoi
#include <cstdio>    // printf, getchar
#include <cstring>   // C-style string by char type 

void init_arrays(int** &A, int* &B, int &rows) {

    // Get number of rows
    scanf("%d", &rows);
    A = new int* [rows];  // Array with Data
    B = new int [rows];   // Array with Column counts 

    // Get column size and fill it
    for (int i=0; i<rows; i++) {
        scanf("%d", &B[i]);
        A[i] = new int[B[i]];
        for (int j=0; j<B[i]; j++) {
           scanf("%d", &A[i][j]); 
        }
    }
}

void print_arrays(int** &A, int* &B, int &rows) {
    //printf("\nRows: %d\n", rows);
    for (int i=0; i<rows; i++) {
        printf("%d: ",B[i]);
        for (int j=0; j<B[i]; j++) {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void remove_row(int** &A, int* &B, int &rows, int row_remove) {
    if (row_remove > rows) return;
    rows --;

    int **newA = new int* [rows];
    for (int i=0; i<row_remove-1; i++) newA[i] = A[i];
    for (int i=row_remove-1; i<rows; i++) newA[i] = A[i+1];    
    delete [] A;
    A = newA;

    int *newB = new int [rows];
    for (int i=0; i<row_remove-1; i++) newB[i] = B[i];
    for (int i=row_remove-1; i<rows; i++) newB[i] = B[i+1];    
    delete [] B;
    B = newB;
}

void find_path(int** &A, int* &B, int &rows, int n, int m, int c = -1) {
    if (m > rows) return;  // check if row number exceed
    if (n-1 > B[n-1]) return;  // check if columns number exceed
    print_arrays(A, B, rows);

    // Update c if it's first iteration
    if (c == -1) c = A[m-1][n-1];
    
    // Self check
    
    if (A[m-1][n-1] == c) A[m-1][n-1] = 0;
    // Look left, check if not already passed
    if (n-1>0)
       if (A[m-1][n-2] != 0) 
           find_path(A, B, rows, n-1, m, c);
    // Look right, check if not already passed
    if (n<B[n])
       if (A[m-1][n] != 0)     
           find_path(A, B, rows, n+1, m, c);
} 


int main() {

    int **A;
    int *B;
    int rows;


    // 1. Init arrays
    init_arrays(A, B, rows);
    //print_arrays(A, B, rows);
          
    // 2. Main code      
    //remove_row(A, B, rows, 2);
    
    find_path(A, B, rows, 4, 3);
    print_arrays(A, B, rows);


    // 9. Delete arrays
    for (int i=0; i<rows; i++) {
        delete [] A[i];
    }
    delete [] A;
    delete [] B;

}