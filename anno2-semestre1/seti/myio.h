#define MY_BUFSIZ 1024
#define MY_EOF -1
typedef struct _MY_FILE {
  int fd;         // Associated file descriptor
  unsigned mod;   // 0 for read , 1 for write
  unsigned flag;  // 0 if everything is fine , 1 is an error occurs
  char *buf;      // the buffer
  char *pos;      // position of the next character to write or to read
  unsigned count; // indicates the number of characters still to be read
  // in the buffer or that can be written
} MY_FILE;
MY_FILE * myfopen(const char * path, char mode);
int myfclose(MY_FILE *fp);
int fillbuffer(MY_FILE *fp);
int flushbuffer(MY_FILE *fp);
int myfgetc(MY_FILE *fp);
int myfputs(int c, MY_FILE *fp);