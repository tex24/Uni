#include "iostream"
#include "vector"
using namespace std;

int trap(vector<int>& height) {
    int s = 0;
    int s1 = 0, n;
    vector<int> copia;
    for(int i=0; i<height.size(); i++){
        s += height[i];
        copia.push_back(height[i]);
    }
    bool trovato;
    for(int i=0; i<height.size()-1; i++){
        trovato=false;
        n = 0;
        int j=i+1;
        while(!trovato){
            j=i+1;
            for(; j<height.size(); j++){
                if(copia[i]-n <= copia[j]){
                    trovato = true;
                    break;
                }
            }
            n++;
        }
        int u = i;
        for(i=i+1; i<j; i++){
            copia[i] = min(copia[u], copia[j]);
        }
        i--;
    }
    for(int i=0; i<copia.size(); i++){
        s1 += copia[i];
        cout << copia[i] << ' ';
    }

    return s1-s;
}

int main(){
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(v);
}