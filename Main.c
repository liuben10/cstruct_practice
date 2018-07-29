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

void testLinkedListReverse() {
  SinglyLinkedList *sll = newSinglyLinkedList();
  sll
    ->add(sll, fromCharBuf("1", 1))
    ->add(sll, fromCharBuf("2", 1))
    ->add(sll, fromCharBuf("123", 3));

  sll->reverse(sll);

  printf("LL=%s\n", sll->toString(sll)->buf);
}

void testHasCycle() {
  SinglyLinkedList *sll = newSinglyLinkedList();
  SLLNode *n1 = newSLLNode(fromCharBuf("123", 3));
  SLLNode *n2 = newSLLNode(fromCharBuf("4", 1));
  SLLNode *n5 = newSLLNode(fromCharBuf("2", 1));
  sll->hp = n5;
  sll->hp->next = n2;
  sll->hp->next->next = n1;
  int hasCycle = hasCycle_SinglyLinkedList(sll);

  printf("\nHas Cycle?: %d\n", hasCycle);
}


void testDoublyLinkedList() {
  DoublyLinkedList *dll = newDoublyLinkedList();
  dll->add(dll, fromCharBuf("123", 3))->add(dll, fromCharBuf("1", 1));
  printf("DLL=%s\n", dll->toString(dll)->buf);
}

int main() {
  testDoublyLinkedList();
  testHasCycle();
  return 0;
}
