#include <stdio.h>
#include <stdlib.h>
#include "String.h"

#pragma once

// ------------------------Typedefs-------------------------------


typedef struct SinglyLinkedList {
  struct SLLNode *hp;
  struct SLLNode *tp;
  int size;
  void(*add)(struct SinglyLinkedList *this, struct String *val);
  struct String*(*toString)(struct SinglyLinkedList *this);
} SinglyLinkedList;


typedef struct DoublyLinkedList {
  struct DLLNode *hp;
  struct DLLNode *tp;
  int size;
  void(*add)(struct DoublyLinkedList *this, struct String *val);
  struct String*(*toString)(struct DoublyLinkedList *this);
} DoublyLinkedList;


typedef struct SLLNode {
  struct String *val;
  struct SLLNode *next;
} SLLNode;

typedef struct DLLNode {
  struct String *val;
  struct DLLNode *next;
  int N;
} DLLNode;

// ----------------------Methods Declarations-----------------------

struct SinglyLinkedList * newSinglyLinkedList();

struct DoublyLinkedList * newDoublyLinkedList();

struct SLLNode * emptySLLNode();

struct DLLNode * emptyDLLNode();

struct SLLNode * newSLLNode(struct String *val);

struct DLLNode * newDLLNode(struct String *val);

void add_SinglyLinkedList(struct SinglyLinkedList *this, struct String *val);

void add_DoublyLinkedList(struct DoublyLinkedList *this, struct String *val);

struct String *toString_SinglyLinkedList(struct SinglyLinkedList *this);

struct String *toString_DoublyLinkedList(struct DoublyLinkedList *this);

// ---------------------Method Implementations----------------------

void add_SinglyLinkedList(struct SinglyLinkedList *this, struct String *val) {
  if (this->hp == NULL) {
    this->tp = newSLLNode(val);
    this->hp = this->tp;
  } else {
    printf("Value of tp (%s), and hp (%s)\n", this->tp->val->toString(*this->tp->val), this->hp->val->toString(*this->hp->val));
    this->tp->next = newSLLNode(val);
    this->tp = this->tp->next;
    this->size += 1;
  }
}

void add_DoublyLinkedList(struct DoublyLinkedList *this, struct String *val) {
  if (this->hp == NULL) {
    this->tp = newDLLNode(val);
    this->hp = this->tp;
  } else {
    this->tp->next = newDLLNode(val);
    this->tp = this->tp->next;
    this->size += 1;
  }
}

struct SLLNode * emptySLLNode() {
  return malloc(sizeof(struct SLLNode));
}

struct DLLNode * emptyDLLNode() {
  return malloc(sizeof(struct DLLNode));
}

struct SLLNode * newSLLNode(struct String * val) {
  struct SLLNode * res = emptySLLNode();
  res->val = val;
  res->next = NULL;
  return res;
}

struct DLLNode * newDLLNode(struct String * val) {
  struct DLLNode * res = emptyDLLNode();
  res->val = val;
  res->next = NULL;
  return res;
} 


struct String *toString_SinglyLinkedList(struct SinglyLinkedList *this) {
  SLLNode * iter = this->hp;
  String * result = newString();
  while(iter != NULL) {
    printf("value=%s\n", iter->val->toString(*iter->val));
    result->append(result, iter->val);
    result->appendBulk(result, "->", 2);

    iter = iter->next;
  }
  return result;
}

struct String *toString_DoublyLinkedList(struct DoublyLinkedList *this) {
  DLLNode * iter = this->hp;
  String * result = newString();
  while(iter != NULL) {
    result->append(result, iter->val);
    result->appendBulk(result, "->", 2);
    
    iter = iter->next;
  }
  return result; 
}

// -------------------Constructors--------------------------------------------

struct SinglyLinkedList * newSinglyLinkedList() {
  SinglyLinkedList *newList = malloc(sizeof(struct SinglyLinkedList));
  newList->hp = NULL;
  newList->tp = NULL;
  newList->size = 0;
  newList->add = &add_SinglyLinkedList;
  newList->toString = &toString_SinglyLinkedList;
  return newList;
}

struct DoublyLinkedList * newDoublyLinkedList() {
  DoublyLinkedList *newList = malloc(sizeof(struct DoublyLinkedList));
  newList->hp = NULL;
  newList->tp = NULL;
  newList->size = 0;
  newList->add = &add_DoublyLinkedList;
  newList->toString = &toString_DoublyLinkedList;
  return newList;
}
