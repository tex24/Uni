#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *f1 = fopen(argv[1], "r");
  FILE *f2 = fopen(argv[2], "r");
  if (!f1 || !f2) {
    printf("errore apertura file");
    return 1;
  }
  char destFile[21];
  for (int i = 0, curr = 0; i < strlen(argv[1]) - 4 || i < strlen(argv[2] - 4);
       i++) {
         if (i < strlen(argv[1]) - 4)
         destFile[curr++] = argv[1][i];
    if (i < strlen(argv[2]) - 4)
      destFile[curr++] = argv[2][i];
  } 
  FILE *dst = fopen(strcat(destFile, ".txt"), "w");
  if (!dst) {
    printf("errore creazione file");
    return 1;
  }
  char buff1[21];
  char buff2[21];
  char c;
  int i = 0, j = 0;
  while ((c = fgetc(f1)) != EOF) {
    if (c == '\n' || c == ' ') {
      if (strlen(buff1) > 0) {
        fputs(buff1, dst);
        fputc(c, dst);
        buff1[0] = '\0';
        i = 0;
      }
    } else {
      buff1[i] = c;
      buff1[i + 1] = '\0';
      i++;
    }
  }
  fclose(f1);
  fclose(f2);
  fclose(dst);
}