#include <iostream>   // cout
#include <cmath>      // pow, sqrt

using namespace std;


const int N = 50;
int main(int argc, char const *argv[])
{
  
    unsigned long m = 1;
    while(m--){
    
        int n;
        long f;
        
        if ( n!=N ) {
            n = N;
            f = (pow((1+sqrt(5))/2, n-1) - pow((1-sqrt(5))/2, n-1))/sqrt(5);
        }    

        //cout << fixed << setprecision(0) << f <<  "\n";
    }
    
    return 0;
}