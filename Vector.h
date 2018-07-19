#include <stdio.h>
#include <stdlib.h>
#include "Util.h"

#define DEFAULT_BUFSIZE 10;

typedef struct IntVector {
  int tail;
  int size;
  int * buf;
  void(*add)(struct IntVector *vector, int element);
  int(*remove)(struct IntVector * vector);
  char*(*toString)(struct IntVector *vector);
  int(*length)(struct IntVector * vector);
  int(*get)(struct IntVector * vector, int idx);
} IntVector;


void add_IntVector(struct IntVector * vector, int element) {
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

int length_IntVector(struct IntVector * vector) {
  return vector->tail;
}

int sizeOfIntsInVector(struct IntVector * vector) {
  int digitsLength = 0;
  for(int i = 0; i < vector->length(vector); i++) {
    digitsLength += numDigits(vector->buf[i]);
  }
  return digitsLength;
}

char * toString_IntVector(struct IntVector * vector) {
  int charBufSize = vector->length(vector) * 2 + sizeOfIntsInVector(vector);
  char * res = malloc(sizeof(char) * charBufSize+1);
  for(int i = 0; i < vector->length(vector); i++) {
    res[i] = vector->buf[i];
  }
  res[vector->length(vector)] = '\0';
  return res;
}

int get(struct IntVector * vector, int idx) {
  return vector->buf[idx];
}

int remove_IntVector(struct IntVector * vector) {
  if (vector->tail > 0) {
    int removed = vector->buf[vector->tail - 1];
    vector->tail = vector->tail - 1;
    return removed;
  } else {
    return 0;
  }
}


struct IntVector * newVector() {
  struct IntVector * result = malloc(sizeof(struct IntVector));
  result->add = &add_IntVector;
  result->remove = &remove_IntVector;
  result->toString = &toString_IntVector;
  result->length = &length_IntVector;
  result->size = DEFAULT_BUFSIZE;
  result->tail = 0;
  result->buf = malloc(sizeof(int) * result->size);
  return result;
}