#include <stdio.h>
#include <stdlib.h>
#include "Util.h"
#pragma once

#define DEFAULT_BUF_SIZE 10

typedef struct String {
  char * buf;
  int tail;
  int bufsize;
  struct String*(*appendChar)(struct String * src, char c);
  struct String*(*append)(struct String *self, struct String *toAppend);
  struct String*(*appendBulk)(struct String * src, char * buf, int N);
  struct String*(*concat)(struct String src, struct String dest);
  char*(*toString)(struct String * self);
  int(*size)(struct String *this);
} String;

String * newString();

int size_String(struct String *this);

struct String* appendChar_String(struct String * src, char c) {
  src->buf[src->tail] = c;
  src->tail += 1;
  if (src->tail >= src->bufsize) {
    int newBufSize = src->bufsize * 2 + 1;
    char * newBuf = malloc(sizeof(char) * newBufSize);
    copyCharBuf(newBuf, 0, src->buf, 0, src->bufsize);
    free(src->buf);
    src->buf = newBuf;
    src->bufsize = newBufSize;
  }
  return src;
}

struct String* appendBulk_String(struct String * src, char * charBuf, int N) {
  for(int i = 0; i < N; i++) {
    src->appendChar(src, charBuf[i]);
  }
  return src;
}

struct String* append_String(struct String *this, struct String *toAppend) {
  return this->appendBulk(this, toAppend->buf, toAppend->tail);
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
  
  free(resultStr->buf);
  
  resultStr->buf = newBuf;
  resultStr->bufsize = result_buf_size;
  resultStr->tail = dest.tail + src.tail;
  return resultStr;
}

int size_String(struct String * string) {
  return string->tail;
}

char * toString_String(struct String * src) {
  return nullTerminated(src->buf, src->tail);
}

struct String * fromCharBuf(char * buf, int N) {
  String * result = newString();
  result->appendBulk(result, buf, N);
  return result;
}
    
String * newString() {
  String * resultStr = malloc(sizeof(String));
  resultStr->buf = malloc(sizeof(char) * DEFAULT_BUF_SIZE);
  resultStr->bufsize = DEFAULT_BUF_SIZE;
  resultStr->tail = 0;
  resultStr->append = &append_String;
  resultStr->appendChar = &appendChar_String;
  resultStr->appendBulk = &appendBulk_String;
  resultStr->concat = &concat_String;
  resultStr->toString = &toString_String;
  resultStr->size = &size_String;
  return resultStr;
}
