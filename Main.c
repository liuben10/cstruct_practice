#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"
#include "LinkedList.h"
#include "Tree.h"
#include "Number.h"

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

void testVectorPartition() {
  int buf[] = {5, 3, 2};
  partition(buf, 0, 3);
  printf("[");
  for(int i = 0; i < 3; i++) {
    printf("%d->%d,", i, buf[i]);
  }
  printf("]\n");

}

void testQuickSort() {
  printf("\n===========Testing Quicksort===========\n");
  int buf2[] = {5, 3, 9, 11, 2, 4, 13};
  sort(buf2, 0, 7);
  printf("[");
  for(int i = 0; i < 7; i++) {
    printf("%d->%d,", i, buf2[i]);
  }
  printf("]\n");
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

void testSortSLL() {
  SinglyLinkedList *sll = newSinglyLinkedList();
  SLLNode *n1 = newSLLNode(fromCharBuf("1", 1));
  SLLNode *n2 = newSLLNode(fromCharBuf("15", 2));
  SLLNode *n5 = newSLLNode(fromCharBuf("2", 1));
  sll->hp = n5;
  sll->hp->next = n2;
  sll->hp->next->next = n1;
  sort_Int_SinglyLinkedList(sll);
  printf("Sorted=%s\n", sll->toString(sll)->buf);
}

void testNumber() {
  int initial[10] = {3,  2,  4,  5,  6,  2,  7,  8,  9,  1};
  Number * initNum = newNumber(initial, 10);
  int toAdd[3] = {2, 1, 1};
  Number *numToAdd = newNumber(toAdd, 3);
  Number *added = add_Number(initNum, numToAdd);
  String *res = added->toString(added);
  res->print(res);
}

void testTreeBalanced() {
  BinaryTree *root = newBinaryTree(10);
  BinaryTree *a = newBinaryTree(5);
  BinaryTree *b = newBinaryTree(8);
  BinaryTree *c = newBinaryTree(12);
  BinaryTree *d = newBinaryTree(14);
  BinaryTree *e = newBinaryTree(16);
  b->left = d;
  b->right = e;
  a->left = b;
  a->left = b;
  a->right = c;
  root->left = a;
  root->right = b;
  
  printf("Is balanced: %d\n", isBalanced(root));
}


void testDoublyLinkedList() {
  DoublyLinkedList *dll = newDoublyLinkedList();
  dll->add(dll, fromCharBuf("123", 3))->add(dll, fromCharBuf("1", 1));
  printf("DLL=%s\n", dll->toString(dll)->buf);
}

int main() {
  /* testDoublyLinkedList(); */
  /* testHasCycle(); */
  /* testSortSLL(); */
  /* testVectorPartition(); */
  /* testQuickSort(); */
  /* testTreeBalanced(); */
  testNumber();
  return 0;
}
