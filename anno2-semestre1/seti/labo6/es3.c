#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void sieve(int read_fd) {
  int p;
  if (read(read_fd, &p, sizeof(int)) <= 0) {
    close(read_fd);
    exit(0);
  }
  printf("%d\n", p);
  fflush(stdout);

  int nextPipe[2];
  pipe(nextPipe);

  int f = fork();

  if (f == 0) {
    close(nextPipe[1]);
    close(read_fd);
    sieve(nextPipe[0]);
    exit(0);
  }

  close(nextPipe[0]);
  int num;

  while (read(read_fd, &num, sizeof(int)) > 0)
    if (num % p != 0)
      write(nextPipe[1], &num, sizeof(int));

  close(read_fd);
  close(nextPipe[1]);
  waitpid(f, NULL, 0);
  exit(0);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s n\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  if (n < 2)
    return 0;

  // Create first pipe
  int pipefd[2];
  if (pipe(pipefd) < 0) {
    perror("pipe");
    exit(1);
  }

  pid_t pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(1);
  }

  if (pid == 0) {
    // CHILD: start the sieve
    close(pipefd[1]); // close write end
    sieve(pipefd[0]);
    exit(0);
  }

  // PARENT: send numbers 2..n
  close(pipefd[0]); // close read end
  for (int i = 2; i <= n; i++) {
    write(pipefd[1], &i, sizeof(int));
  }
  close(pipefd[1]);

  wait(NULL); // wait for sieve to finish
  return 0;
}
