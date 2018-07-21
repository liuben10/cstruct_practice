#include <stdlib.h>
#include <stdio.h>
#include "String.h"


int main() {

  String * test = newString();
  test->append(test, 'h');
  test->append(test, 'i');
  printf("Out=%s\n", test->toString(*test));
  String * test2 = newString();
  test2->append(test2, ' ');
  test2->append(test2, 'w');
  test2->append(test2, 'o');
  test2->append(test2, 'r');
  test2->append(test2, 'l');
  test2->append(test2, 'd');
  String * concatted = test->concat(*test, *test2);
  printf("Concattenation output=%s\n", concatted->toString(*concatted));
}
