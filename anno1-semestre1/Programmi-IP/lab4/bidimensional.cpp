#include <iostream>
using namespace std;

int main(){
    const int M = 5;
    const int N = 8;
    int a[M][N];

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            a[i][j] = i;
        }
    }
    cout << endl;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}