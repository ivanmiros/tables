// ...
#include <string>       // string
#include <iostream>     // cout
#include <sstream>      // stringstream
#include <cstring>      // memset
using namespace std;


// print square 2D array
void command_w(long ** &A, int size) {
    for (int i=0 ; i<size ; i++){
        for (int j=0 ; j<size-1 ; j++ ) cout << A[i][j] << " ";
        cout << A[i][size-1] << endl;
    }

}

// move numbers horisontally, left = 0, right = 1
bool move_h(long ** &A, int size, int direction) {
    bool action = false;
    for (int i = 0 ; i < size; i++ ) {    
        
        int check = 0;
        int j_zerro = 0;

        // reduce time, skip rows with only 0's
        for (int j = 0 ; j < size; j++ ) check += A[i][j];
        if (check >0)
            for (int j = 0 ; j < size; j++ ) {

                int j_index = (direction ==0) ? j : size-j-1;
                int j_zindex = (direction ==0) ? j_zerro : size-j_zerro-1;

                if (A[i][j_index] != 0 && A[i][j_zindex] == 0) { 
                    A[i][j_zindex] = A[i][j_index];         
                    A[i][j_index] = 0;                    
                    action = true;                      // flag that at least one action is taken 
                }
                if (A[i][j_zindex] != 0) j_zerro ++;    // move pointer if place already taken
            }
    }
    return action;
}


// squeeze to the left
bool squeeze_l(long ** &A, int size) {

    // do not start for 1x1 matrix 
    if (size <2) return false;

    bool action = false;
    for (int i = 0 ; i < size; i++ ) {    

        long check = 0;

        // reduce time, skip rows with only 0's
        for (int j = 0 ; j < size; j++ ) check += A[i][j];
        if (check >0)
            for (int j = 0 ; j < size-1; j++ ) {
                if (A[i][j] != 0 && A[i][j+1] != 0) {
                    if (A[i][j+1]%A[i][j] == 0) {
                        A[i][j+1] -= A[i][j];
                        A[i][j] *= 2;
                        action = true;                 // flag that at least one action is taken
                        break;
                    }
                }
            }
    }
    return action;
}


void command_l(long ** &A, int size) {
    // loop until both are false - no more actions
    while (move_h(A, size, 0) || squeeze_l(A, size)) {};
}


// get sum if square matrix
void command_s(long ** &A, int size) {
    long sum = 0;
    for (int i = 0; i < size; i++ ) {    
        for (int j = 0; j < size; j++ ) {
            sum += A[i][j];
        }
    }
    cout << sum << endl;
}



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


// do command N: input string format [N x y w]
void command_n(long ** &A, string &input) {
    stringstream ss(input);
    string word;
    ss >> word;  // N
    ss >> word;
    int x = stoi(word);
    ss >> word;
    int y = stoi(word);
    ss >> word;
    int w = stoi(word);
    A[x-1][y-1] = w;
}

// do command C: input string format [C M p00 p01 ... p[M-1][M-1]]
void command_c(long ** &A, int &size, string &input) {
    // Delete prev array
    delete_array(A,size);

    stringstream ss(input);
    string word;
    ss >> word;  // C

    ss >> word;  // M
    size = stoi(word);
    init_array(A,size);  // new array MxM

    for (int i = 0; i < size; i++ ) {    
        for (int j = 0; j < size; j++ ) {
            ss >> word;
            A[i][j] = stoi(word);
        }
    }
}


int main() {

    string cc = "C 12 0 0 1 1 0 4 0 4 2 0 2 0 2 1 1 1 5 4 5 4 2 5 2 5 2 1 1 1 5 4 0 4 2 0 2 0 2 1 1 1 0 4 0 4 2 0 2 0 2 1 1 1 0 4 0 4 2 0 2 0 2 1 1 1 0 4 0 4 2 0 2 0 2 1 1 1 0 4 0 4 2 0 2 0 2 1 1 1 0 4 0 4 2 0 2 0 2 1 1 1 0 4 0 4 2 0 2 0 2 1 1 1 0 4 0 4 2 0 2 0 2 1 1 1 0 4 0 4 2 0 2 0 2 1 1 1 0 4 0 4 2 0 2 0";
     
    long **A;
    int M;
    
    
    //cin >> M;
    M=10;

    init_array(A,M);

    while(1) {

        string input;
        getline (cin, input);
        
        if (!input.compare("K")) break;
        if (!input.compare("S")) command_s(A,M);
        if (input.at(0) == 'N') command_n(A,input);
        if (input.at(0) == 'C') command_c(A,M,cc);
        if (!input.compare("W")) command_w(A,M);
        if (!input.compare("L")) command_l(A,M);

    }

    command_s(A,M);
    delete_array(A,M);

}