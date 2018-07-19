#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int * copyNewBuf(int * srcBuf, int srcIdx, int amountToCopy) {
  int * result = malloc(sizeof(int) * amountToCopy);
  for(int i = 0; i < amountToCopy; i++) {
    result[i] = srcBuf[srcIdx + i];
  }
  return result;		     
}

void copyIntBuf(int * srcBuf, int srcIdx, int * destBuf, int destBufIdx, int amountToCopy) {
  for(int i = 0; i < amountToCopy; i++) {
    destBuf[i + destBufIdx] = srcBuf[srcIdx + i];
  }
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