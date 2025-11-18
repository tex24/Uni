#include <stdio.h>
#include <unistd.h>

void win(void) {
	execve("/bin/sh", NULL, NULL);
}

int main(void) {
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	
	char text[32] = {};

	puts("Let's see what you've got");
	gets(text);
}
