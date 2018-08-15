#include "string.h"

#pragma once

#define DEFAULT_BUF_SIZE 100			

typedef struct HashMap {
  void *(*get)(struct HashMap *this, String *key);
  void (*put)(struct HashMap *this, String *key, void *value);
  void *(*remove)(struct HashMap *this, String *key);

  int bufsize;
  void **buf;
} HashMap;

int hash(struct HashMap *this, String *key) {
  char *raw = key->buf;
  int sum = 0;
  for(int i = 0; i < key->size(key); i++) {
    sum += (unsigned int) raw[i];
  }
  return sum % this->bufsize;
}

void *get_HashMap(struct HashMap *this, String *key) {
  int slotIdx = hash(this, key);
  return this->buf[slotIdx];
}

void put_HashMap(struct HashMap *this, String *key, void *value) {
  int slotIdx = hash(this, key);
  this->buf[slotIdx] = value;
}

struct HashMap *newHashMap() {
  HashMap *map = malloc(sizeof(struct HashMap));
  map->get = &get_HashMap;
  map->put = &put_HashMap;
  map->buf = malloc(sizeof(void *) * DEFAULT_BUF_SIZE);
  return map;
}
