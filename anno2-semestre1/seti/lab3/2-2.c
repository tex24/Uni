#include <stdio.h>
int main() {
  FILE *f = fopen("fic.txt", "r");
  fseek(f, 0, SEEK_END);
  long t = ftell(f);
  printf("%ld \n", t);
  fseek(f, -5, SEEK_END);
  char s[4];
  fgets(s, 4, f);
  printf("%s\n", s);
  return 0;
}