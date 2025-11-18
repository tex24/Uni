#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int main() {
  unsigned int i = 0;
  int bufferSize = 64;
  char *s = malloc(bufferSize);
  fgets(s, bufferSize, stdin);
  for (unsigned int j = 2; s[strlen(s) - 1] != '\n'; j++) {
    s = realloc(s, bufferSize * j);
    fgets(s+strlen(s), bufferSize * j, stdin);
  }
  for (i = 0; i < strlen(s); i++) {
    if (97 <= s[i] && s[i] <= 122)
      s[i] = (((s[i] - 97) + 13) % 26) + 97;
  }
  fputs(s, stdout);
  return 0;
}*/

int main() {
  unsigned int i = 0;
  FILE *flux = fopen("./boh.txt", "r");
  if(flux == NULL){
    perror("Errore file");
    return 1;
  }
  int bufferSize = 255;
  char *s = malloc(bufferSize);
  char riga[255];
  int n=1;
  while(fgets(riga, bufferSize, flux) != NULL){
    if(strlen(riga) >= bufferSize * n - strlen(s)){
      n++;
      s = realloc(s, bufferSize*n);
    }
    strcat(s, riga);
  }


  for (i = 0; i < strlen(s); i++) {
    if (97 <= s[i] && s[i] <= 122)
      s[i] = (((s[i] - 97) + 13) % 26) + 97;
  }
  fputs(s, stdout);
  return 0;
}