
#include <cstdlib>   // malloc, free, atoi
#include <cstdio>    // printf, getchar
#include <cstring>   // C-style string by char type 

void init_arrays(int** &A, int* &B, int &rows) {

    // Get number of rows
    scanf("%d", &rows);
    A = new int* [rows];  // Array with Data
    B = new int [rows];   // Array with size of rows (y) 

    // Get column size and fill it
    for (int i=0; i<rows; i++) {
        scanf("%d", &B[i]);      // Get size of row (y)
        A[i] = new int[B[i]];    // Create row with (x) elements 
        for (int j=0; j<B[i]; j++) {
           scanf("%d", &A[i][j]); 
        }
    }
}

void print_arrays(int** &A, int* &B, int &rows) {
    //printf("\nRows: %d\n", rows);
    for (int y=0; y<rows; y++) {
        printf("%d: ",B[y]);
        for (int x=0; x<B[y]; x++) {
            printf("%d ",A[y][x]);
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

void find_path(int** &A, int* &B, int &rows, int x, int y, int c = -1) {
    // A[y][x]  <- 'y' on first place
    printf("Check: %d, %d\n", x, y);
    if (y > rows) return;    // check if row number exceed
    if (x > B[y-1]) return;  // check if columns number exceed


    // Save c if it's first iteration
    
    if (c == -1) c = A[y-1][x-1];
    
    // Self check if already passed
    if (A[y-1][x-1] == 0) {
        printf("It's zero, exit\n");
        return;
    }
    
    // Self check set to zero
    if (A[y-1][x-1] == c) { 
        A[y-1][x-1] = 0;
        printf("Set self to zero\n");
    } else {
        printf("It's not C, exit\n");
        return;
    }
    
    print_arrays(A, B, rows);

    // Look left, skip if already zero
    if (x-1>0)
       if (A[y-1][x-2] != 0) {
            printf("Go left\n");
            find_path(A, B, rows, x-1, y, c);
       }

    // Look right
    if (x<B[y-1])
       if (A[y-1][x] != 0) {
            printf("Go right\n");    
            find_path(A, B, rows, x+1, y, c);
       }

    // Look up, check if cell is exist
    if (y-1>0 && x-1<B[y-2])
       if (A[y-2][x-1] != 0) {
            printf("Go up\n");     
            find_path(A, B, rows, x, y-1, c);
       }

    // Look down, check if cell is exist
    if (y<rows && x-1<B[y])
       if (A[y][x-1] != 0) {
            printf("Go down\n");     
            find_path(A, B, rows, x, y+1, c);
       }

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