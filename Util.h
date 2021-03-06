#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#pragma once

char * nullTerminated(char * src, int N);

int max(int x, int y) {
  if (x < y) {
    return y;
  }
  return x;
}

int * copyNewBuf(int * srcBuf, int srcIdx, int amountToCopy) {
  int * result = malloc(sizeof(int) * amountToCopy);
  for(int i = 0; i < amountToCopy; i++) {
    result[i] = srcBuf[srcIdx + i];
  }
  return result;		     
}

int abs(int n) {
  if (n < 0) {
    return -1 * n;
  } else {
    return n;
  }
}


void copyIntBuf(int * destBuf, int destIdx, int * srcBuf, int srcIdx, int amountToCopy) {
  for(int i = 0; i < amountToCopy; i++) {
    destBuf[i + destIdx] = srcBuf[srcIdx + i];
  }
}

void copyCharBuf(char * destBuf, int destIdx, char * srcBuf, int srcIdx, int amountToCopy) {
  for(int i = 0; i < amountToCopy; i++) {
    destBuf[i + destIdx] = srcBuf[srcIdx + i];
  }
}

char * nullTerminated(char * src, int N) {
  char * result = malloc(sizeof(char) * N+1);
  for(int i = 0; i < N; i++) {
    result[i] = src[i];
  }
  result[N] = '\0';
  return result;
}

int numDigits(int n) {
  int size = 0;
  while (n > 0) {
    n /= 10;
    size += 1;
  }
  return size;
}

char digtoa(int val) {
  if (val < 10 && val >= 0) {
    return val + '0';
  } else {
    return '\0';
  }
}

char * itoa(int val) {
  int n = numDigits(val);
  char * result = malloc(n * sizeof(char));
  
  while (val > 0) {
    int toAdd = val % 10;
    result[n-1] = digtoa(toAdd);
    val /= 10;
    n -= 1;
  }
  return result;
}
