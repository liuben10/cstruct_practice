#include <stdlib.h>
#include "String.h"
#pragma once

typedef struct  Number {
  int *bytes;
  int length;
  String *(*toString)(struct Number *this);
} Number;

String *toString(struct Number *this);

struct Number *add_Number(struct Number *this, struct Number *other);

String *toString_Number(struct Number *this) {
  String *res = newString();
  for(int i = 0; i < this->length; i++) {
    res->appendChar(res, digtoa(this->bytes[i]));
  }
  return res;
}

struct Number *add_Number(struct Number *this, struct Number *other) {
  int maxLength = max(this->length, other->length);
  Number *longest;
  Number *shortest;
  if (maxLength == this->length) {
    longest = this;
    shortest = other;
  } else {
    longest = other;
    shortest = this;
  }

  Number *added = malloc(sizeof(Number));
  int addedLength = (longest->length + 1);
  added->bytes = malloc(sizeof(int) * addedLength);
  added->length = addedLength;
  
  // actually perform addition
  
  int longIdx = longest->length - 1;
  int shortIdx = shortest->length - 1;
  int resIdx = added->length - 1;
  int carry = 0;
  int sum = 0;
  int res = 0;
  printf("Longest: %d. Shortest: %d\n", longIdx, shortIdx);

  int longElem;
  int shortElem;
  
  while (longIdx >= 0 && shortIdx >= 0) {
    longElem = longest->bytes[longIdx];
    shortElem = shortest->bytes[shortIdx];
    sum = longElem + shortElem + carry;
    carry = sum / 10;
    res = sum % 10;
    added->bytes[resIdx] = res;
    
    longIdx -= 1;
    shortIdx -= 1;
    resIdx -= 1;
  }
  
  while (longIdx >= 0) {
    sum = longest->bytes[longIdx] + carry;

    carry = sum / 10;
    res = sum % 10;
    added->bytes[resIdx] = res;

    longIdx -= 1;
    resIdx -= 1;
  }
  return added;
}

struct Number *newNumber(int *initial, int N) {
  Number *res = malloc(sizeof(Number));
  res->length = N;
  res->bytes = initial;
  res->toString = &toString_Number;
  return res;
}
