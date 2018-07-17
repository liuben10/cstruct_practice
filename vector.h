#include <stdio.h>
#include <stdlib.h>
#include "Util.h"

#define DEFAULT_BUFSIZE 10;

typedef struct IntVector {
  int tail;
  int size;
  int * buf;
  void(*add)(IntVector *vector, int element);
  int(*remove)(IntVector * vector);
  char*(*toString)(IntVector *vector);
  int(*length)(IntVector * vector);
} IntVector;

IntVector * newVector() {
  IntVector * result = malloc(sizeof(IntVector));
  result->add = &add_IntVector;
  result->remove = &remove_IntVector;
  result->toString = &toString_IntVector;
  result->length = &length_IntVector;
  result->size = DEFAULT_BUFSIZE;
  result->tail = 0;
  result->buf = malloc(sizeof(int) * result->size);
  return result;
}

void add_IntVector(IntVector * vector, int element) {
  if (vector->tail < vector->size) {
    vector->buf[vector->tail] = element;
    vector->tail += 1;
  } else {
    int oldSize = vector->size;
    vector->size = vector->size * 2 + 1;
    int * newBuf = malloc(sizeof(int) * vector->size);
    copyIntBuf(vector->buf, 0, newBuf, 0, oldSize);
    vector->buf = newBuf;
    vector->buf[vector->tail] = element;
    vector->tail += 1;
  }
}

int length_IntVector(IntVector * vector) {
  return vector->tail;
}

int sizeOfIntsInVector(IntVector * vector) {
  int digitsLength = 0;
  for(int i = 0; i < vector->length(); i++) {
    digitsLength += numDigits(vector->buf[i]);
  }
  return digitsLength;
}

char * toString_IntVector(IntVector * vector) {
  int charBufSize = vector->length() * 2 + sizeOfIntsInVector(vector);
  char * res = malloc(sizeof(char) * charBufSize+1);
  for(int i = 0; i < vector->length(); i++) {
    res[i] = vector->buf[i];
  }
  res[vector->length()] = '\0';
  return res;
}

void remove_IntVector(IntVector * vector) {
  if (vector->tail > 0) {
     vector->tail = vector->tail - 1;
  }
}
