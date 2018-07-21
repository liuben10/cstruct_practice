#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"


int main() {
  IntVector * vector = newVector();
  vector->add(vector, 12);
  vector->add(vector, 13);
  
  printf("%s\n", vector->toString(vector));
}
