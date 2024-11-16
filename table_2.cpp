
#include <cstdlib>   // malloc, free, atoi
#include <cstdio>    // printf, getchar
#include <cstring>   // C-style string by char type 




void delete_array(long ** &A, int size) {

    // delete rows first
    for(int i = 0; i < size; i++) {
        delete [] A[i];
    }
    // delete entry points
    delete [] A;

}

void init_array(long ** &A, int size) {
    // Array of pointers - columns
    A = new long* [size];
    // Add arrays of rows + init to 0
    for(int i = 0; i < size; i++) {
        A[i] = new long[size];
        memset(A[i], 0, sizeof(long)*size);
    }
}


int main() {

     
    int **A;
    int start_rows;
    

    scanf("%d", &start_rows);
    A = new int* [start_rows];

    int B[start_rows];

    for (int i=0; i<start_rows; i++) {
        scanf("%d", &B[i]);
        A[i] = new int[B[i]];
        for (int j=0; j<B[i]; j++) {
           scanf("%d", &A[i][j]); 
        }
    }

    for (int i=0; i<start_rows; i++) {
        for (int j=0; j<B[i]; j++) {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
          
    



}