#include <string>

using namespace std;

int maxArray(int* t,int size){
  int max = t[0];
  for(int i=1; i<size; i++){
      if(t[i] > max)
          max = t[i];
  }
  return max;
}
