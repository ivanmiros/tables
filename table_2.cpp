
#include <cstdlib>   // malloc, free, atoi
#include <cstdio>    // printf, getchar
#include <cstring>   // C-style string by char type 



int main() {
     
    int **A;
    int start_rows;


    // 1. Init arrays
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
          
    // 2. Main code      
    










    // 9. Delete arrays
    for (int i=0; i<start_rows; i++) {
        delete [] A[i];
    }
    delete [] A;

}