#include <stdio.h>
#include <stdlib.h>

typedef struct Tuple {
  void *first;
} Tuple;

int main() {
  Tuple *t = malloc(sizeof(Tuple));
  t->first = malloc(sizeof(char));
  ((char *) t->first)[0] = 'c';
  char *pulled = (char *)t->first;
  printf("%s\n", t->first);
  return 0;
}
