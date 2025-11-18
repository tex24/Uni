#include <iostream>
#include <cmath>
using namespace std;

int main(){
    const int N = 10;
    const int M = 20;
    const int K = N+M;

    int s1[N];
    int s2[M];
    int d[K];

    srand(time(NULL));

    for(int i=0; i<N; i++){
        int randomNumber = (rand()%256);
        s1[i] = randomNumber;
    }
    for(int i=0; i<M; i++){
        int randomNumber = (rand()%256);
        s2[i] = randomNumber;
    }

    cout << "Array s1 (generato) = { ";
    for(int i=0; i<N; i++){
        if(i != N-1) cout << s1[i] << ", ";
        else cout << s1[i] << " }\n";
    }
    cout << "Array s2 (generato) = { ";
    for(int i=0; i<M; i++){
        if(i != M-1) cout << s2[i] << ", ";
        else cout << s2[i] << " }\n";
    }
    // ordino s1
    for(int i=0; i<N-1; i++){
        int minIndex = i;
        for(int j=i+1; j<N; j++){
            if(s1[j] < s1[minIndex]) minIndex = j;
        }
        if(minIndex != i){
            int a = s1[i];
            s1[i] = s1[minIndex];
            s1[minIndex] = a;
        }
    }
    // ordino s2
    for(int i=0; i<M-1; i++){
        int minIndex = i;
        for(int j=i+1; j<M; j++){
            if(s2[j] < s2[minIndex]) minIndex = j;
        }
        if(minIndex != i){
            int a = s2[i];
            s2[i] = s2[minIndex];
            s2[minIndex] = a;
        }
    }
    cout << "Array s1 (ordinato) = { ";
    for(int i=0; i<N; i++){
        if(i != N-1) cout << s1[i] << ", ";
        else cout << s1[i] << " }\n";
    }
    cout << "Array s2 (ordinato) = { ";
    for(int i=0; i<M; i++){
        if(i != M-1) cout << s2[i] << ", ";
        else cout << s2[i] << " }\n";
    }

    //popolo l array d
    int is1 = 0;
    int is2 = 0;

    for(int i=0; i<K; i++){
        if(is1 == N){
            d[i] = s2[is2++];
        }
        else if(is2 == M) {
            d[i] = s1[is1++];
        }else{
            if(s1[is1] <= s2[is2]) d[i] = s1[is1++];
            else d[i] = s2[is2++];
        }
    }

    cout << "Array d = { ";
    for(int i=0; i<K; i++){
        if(i != K-1) cout << d[i] << ", ";
        else cout << d[i] << " }\n";
    }


}