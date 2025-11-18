
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "myio.h"
#include <unistd.h>

MY_FILE * myfopen(const char * path, char mode){
    MY_FILE *file = malloc(sizeof(MY_FILE));
    if(file == NULL)
        return NULL;
    if(mode == 'r'){
        file->mod = 0;
        file->fd = open(path, O_RDONLY);
        file->count = 0;
    }else if(mode == 'w'){
        file->mod = 1;
        file->fd = open(path, O_WRONLY);
        file->count = MY_BUFSIZ;
    }else{
        return NULL;
    }
    if(file->fd < 0){
        return NULL;
    }
    file->flag = 0;    
    file->buf = malloc(MY_BUFSIZ * sizeof(char));
    file->pos = file->buf;
    return file;
}

int flushBuffer(MY_FILE *fp){
    if(!fp) return 1;     
    write(fp->fd, fp->buf, fp->pos - fp->buf);
}

int myfclose ( MY_FILE *fp ){
    flushBuffer(fp);
    int ris = close(fp->fd);
    free(fp->buf);
    free(fp);
    return ris;
}


int fillbuffer(MY_FILE *fp){
    if(!fp || fp->mod != 0) return MY_EOF;
    fp->count = read(fp->fd, fp->buf, MY_BUFSIZ);

}


