#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"
#include "LinkedList.h"

void testVector() {
  IntVector * vector = newVector();
  vector->add(vector, 12);
  vector->add(vector, 13);
  vector->add(vector, 14);
  vector->add(vector, 15);
  vector->add(vector, 16);
  vector->add(vector, 55);
  vector->add(vector, 66);
  vector->add(vector, 77);
  vector->add(vector, 1);
  vector->add(vector, 2);
  vector->add(vector, 3);
  printf("Vector=%s\n", vector->toString(vector));

  int removed = vector->remove(vector);
  printf("Removed=%d\n", removed);
  printf("Vector=%s\n", vector->toString(vector)); 
}

void testLinkedList() {
  SinglyLinkedList *sll = newSinglyLinkedList();
  sll
    ->add(sll, fromCharBuf("1", 1))
    ->add(sll, fromCharBuf("2", 1))
    ->add(sll, fromCharBuf("123", 3));

  printf("LL=%s\n", sll->toString(sll)->buf);
}

int main() {
  testLinkedList();
  
  return 0;
}
