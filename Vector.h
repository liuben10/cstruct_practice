#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Util.h"
#include "String.h"
#pragma once

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
  vector->buf[vector->tail] = element;
  vector->tail += 1;
  if (vector->tail >= vector->size) {
    int newVectorSize = vector->size * 2 + 1;
    int * newBuf = malloc(sizeof(int) * newVectorSize);
    copyIntBuf(newBuf, 0, vector->buf, 0, vector->size);
    free(vector->buf);
    vector->buf = newBuf;
    vector->size = newVectorSize;
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
  String * resultString = newString();
  for(int i = 0; i < vector->tail; i++) {  
    resultString->appendBulk(resultString, itoa(vector->buf[i]), numDigits(vector->buf[i]));
    resultString->appendBulk(resultString, ", ", 2);
  }
  return resultString->toString(resultString);
}


int get_Vector(struct IntVector * vector, int idx) {
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

void swap(int *buf, int N, int i, int j) {
  printf("Swapping: N=%d, i=%d, j=%d\n", N, i, j);
  if (i >= N || j >= N) {
    printf("Error, i and j must be less than N");
    exit(1);
  } else {
    int tmp = buf[i];
    buf[i] = buf[j];
    buf[j] = tmp;
  }
}


int partition(int *buffer, int startIdx, int N) {
  printf("Partitioning startIdx=%d, N=%d\n", startIdx, N);
  srand(time(0));
  int partitionIdx = (rand() % N) + startIdx;
  printf("partitionIdx=%d\n", partitionIdx);
  int partition = buffer[partitionIdx];
  swap(buffer, N + startIdx, partitionIdx, startIdx + N - 1);
  int slow = startIdx;
  int fast;
  for(fast = startIdx + 1; fast < N + startIdx; fast++) {
    if (buffer[fast] < partition) {
      swap(buffer, N + startIdx, fast, slow);
    }
    if (buffer[slow] < partition) {
      slow += 1;
    }
  }

  swap(buffer, N + startIdx, startIdx + N - 1, slow);
  return slow;
}

void sort(int *buf, int startIdx, int N) {
  printf("N=%d, startIdx=%d\n", N, startIdx);
  if (N <= 1) {
    return;
  }
  int partitionIdx = partition(buf, startIdx, N);
  sort(buf, startIdx, partitionIdx - startIdx);
  sort(buf, partitionIdx, N - partitionIdx);
}


struct IntVector * newVector() {
  struct IntVector * result = malloc(sizeof(struct IntVector));
  result->add = &add_IntVector;
  result->remove = &remove_IntVector;
  result->toString = &toString_IntVector;
  result->length = &length_IntVector;
  result->get = &get_Vector;
  result->size = DEFAULT_BUFSIZE;
  result->tail = 0;
  result->buf = malloc(sizeof(int) * result->size);
  return result;
}
