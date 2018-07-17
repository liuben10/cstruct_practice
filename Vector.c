#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main() {

  IntVector * newVector = newVector();
  newVector->add(newVector, 10);
  newVector->add(newVector, 12);
  newVector->add(newVector, 13);
  printf("resultant_vector=%s\n", newVector->toString(newVector));
}
