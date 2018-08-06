#include "string.h"

#pragma once

#define DEFAULT_BUF_SIZE 100			\

typedef struct HashMap {
  (void *) (*get)(HashMap *this, String key);
  void (*put)(HashMap *this, String key, void *value);
  (void *) (*remove)(HashMap *this, String key);

  int bufsize;
  void * buf;
} HashMap;

int hash(String key);

void * get_HashMap(HashMap *this, String key) {
  int slotIdx = hash(key) % this->bufsize;
  return this->buf[slotIdx];
}

void put_HashMap(HashMap *this, String key, void *value) {
  int slotIdx = hash(key) % this->bufsize;
  this->buf[slotIdx] = value;
}

HashMap *newHashMap() {
  HashMap *map = malloc(sizeof(HashMap));
  map->get = &get_HashMap;
  map->put = &put_HashMap;
  
}



    

