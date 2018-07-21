#include <stdio.h>
#include <stdlib.h>
#include "Util.h"
#pragma once

#define DEFAULT_BUF_SIZE 10

typedef struct String {
  char * buf;
  int tail;
  int bufsize;
  void(*append)(struct String * src, char c);
  void(*appendBulk)(struct String * src, char * buf, int N);
  struct String*(*concat)(struct String src, struct String dest);
  char*(*toString)(struct String self);
} String;

String * newString();

void append_String(struct String * src, char c) {
  src->buf[src->tail] = c;
  src->tail += 1;
  if (src->tail >= src->bufsize) {
    char * newBuf = malloc(sizeof(char) * src->bufsize * 2 + 1);
    copyCharBuf(newBuf, 0, src->buf, 0, src->bufsize);
  }
}

void appendBulk_String(struct String * src, char * charBuf, int N) {
  for(int i = 0; i < N; i++) {
    src->append(src, charBuf[i]);
  }
}


struct String * concat_String(struct String src, struct String dest) {
  int result_buf_size = src.bufsize + dest.bufsize;
  String * resultStr = newString();
  char * newBuf = malloc(sizeof(char) * result_buf_size);
  for(int i = 0; i < src.tail; i++) {
    newBuf[i] = src.buf[i];
  }

  for(int j = src.tail; j < dest.tail + src.tail; j++) {
    newBuf[j] = dest.buf[j - src.tail];
  }
  
  resultStr->buf = newBuf;
  resultStr->bufsize = result_buf_size;
  resultStr->tail = dest.tail + src.tail;
  return resultStr;
}

char * toString_String(struct String src) {
  return nullTerminated(src.buf, src.tail);
}
    
String * newString() {
  String * resultStr = malloc(sizeof(String));
  resultStr->buf = malloc(sizeof(char) * DEFAULT_BUF_SIZE);
  resultStr->bufsize = DEFAULT_BUF_SIZE;
  resultStr->tail = 0;
  resultStr->append = &append_String;
  resultStr->appendBulk = &appendBulk_String;
  resultStr->concat = &concat_String;
  resultStr->toString = &toString_String;
  return resultStr;
}
