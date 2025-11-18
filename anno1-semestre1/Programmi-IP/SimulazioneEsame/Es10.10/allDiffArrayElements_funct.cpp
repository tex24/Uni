bool allDiffArrayElements(int* t,int size){
  for(int i=0; i<size; i++){
      for(int j=0; j<size; j++){
          if(t[i] == t[j] and i != j)
              return false;
      }
  }
  return true;
}
