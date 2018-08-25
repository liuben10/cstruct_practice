#include <stdlib.h>
#include "Util.h"

#define DEFAULT_RANGE_SIZE = 10;

typedef struct Pair {
  int x;
  int y;
} Pair;


typedef struct Ranges {
  struct Pair * ranges;
  int tail;
  int bufsize;
  void(*add)(struct Ranges *this, Pair *pairs);
} Ranges;


Ranges *copy_Ranges(struct Ranges *this, int newSize) {
  Pair *pairs = malloc(sizeof(Pair) * newSize);
  for(int i = 0; i < this->tail; i++) {
    pairs[i] = this->ranges[i];
  }
  Ranges *newRanges = malloc(sizeof(Ranges));
  newRanges->bufsize = newSize;
  newRanges->tail = this->tail;
  return newRanges;
}

Ranges add_Ranges(struct Ranges *this, Pair *pairs) {
  if (this->tail < this->bufsize) {
    this->ranges[tail] = pairs;
    this->tail += 1;
    return this;
  } else {
    Ranges *newRanges = copyRanges(this, this->bufsize * 2 + 1);
    newRanges->[tail] = pairs;
    newRanges->tail += 1;
    return newRanges;
}

Ranges *newRanges() {
  Ranges *this = malloc(sizeof(Ranges) * DEFUALT_RANGE_SIZE);
  this->add = &add_Ranges;
  return this;
}



