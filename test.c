#include <stdio.h>
#include <stdlib.h>

#define DM(x, y) x y;

#define CLASS(T)					\
  struct T *new_##T() {					\
    T *result = malloc(sizeof(T));			\
    result->this = result;				\
    result->new = &new_##T;				\
    return result;					\
  }							\

typedef struct Tuple {
  int x;
  int y;
  struct Tuple *this;
  struct Tuple *(*new)();
} Tuple;

CLASS(Tuple);

int main(){
  Tuple *result = new_Tuple();
  result->x = 10;
  result->y = 11;
  printf("x=%d, y=%d\n", result->x, result->y);
}
