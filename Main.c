#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"


int main() {
  IntVector * vector = newVector();
  vector->add(vector, 12);
  vector->add(vector, 13);
  vector->add(vector, 14);
  vector->add(vector, 15);
  vector->add(vector, 16);
  
  printf("Vector=%s\n", vector->toString(vector));

  return 0;
}
