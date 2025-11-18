#include <complex.h>
#include <stdio.h>
#include <string.h>

void reverse(char *s) {
  const char *ext = ".txt";
  if (strlen(s) < strlen(ext) || strcmp(s + strlen(s) - strlen(ext), ext)) {
    printf("inserisci un file .txt");
    return;
  }
  FILE *f = fopen(s, "r");
  if (!f) {
    printf("Errore apertura file");
    return;
  }
  fseek(f, 0, SEEK_END);
  long pos = ftell(f);
  char c = fgetc(f);
  int i = -1;
  FILE *dest = fopen("ris.txt", "w");
  while (pos > 0) {
	fseek(f, i--, SEEK_END);
	c = fgetc(f);
	pos--;
	fputc(c, dest);
  }
}

int main() {
	reverse("ciao.txt");
}
