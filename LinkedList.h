#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "String.h"

#pragma once

// ------------------------Typedefs-------------------------------


typedef struct SinglyLinkedList {
  struct SLLNode *hp;
  struct SLLNode *tp;
  int size;
  struct SinglyLinkedList*(*add)(struct SinglyLinkedList *this, struct String *val);
  struct String*(*toString)(struct SinglyLinkedList *this);
  void(*reverse)(struct SinglyLinkedList *this);
} SinglyLinkedList;


typedef struct DoublyLinkedList {
  struct DLLNode *hp;
  struct DLLNode *tp;
  int size;
  struct DoublyLinkedList*(*add)(struct DoublyLinkedList *this, struct String *val);
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

int hasCycle_SinglyLinkedList(struct SinglyLinkedList *sll);

struct SinglyLinkedList * newSinglyLinkedList();

struct DoublyLinkedList * newDoublyLinkedList();

struct SLLNode * emptySLLNode();

struct DLLNode * emptyDLLNode();

struct SLLNode * newSLLNode(struct String *val);

struct DLLNode * newDLLNode(struct String *val);

struct SinglyLinkedList * add_SinglyLinkedList(struct SinglyLinkedList *this, struct String *val);

struct DoublyLinkedList * add_DoublyLinkedList(struct DoublyLinkedList *this, struct String *val);

struct String *toString_SinglyLinkedList(struct SinglyLinkedList *this);

struct String *toString_DoublyLinkedList(struct DoublyLinkedList *this);

void reverse_SinglyLinkedLists(struct SinglyLinkedList *this);

// ---------------------Method Implementations----------------------

int hasCycle_SinglyLinkedList(struct SinglyLinkedList *sll) {
  SLLNode *slowPtr = sll->hp;
  SLLNode *fastPtr = NULL;
  if (slowPtr->next != NULL) {
    fastPtr = slowPtr->next;
    while (fastPtr != NULL) {
      if (fastPtr == slowPtr) {
	return 1;
      }
      if (fastPtr->next != NULL) {
	fastPtr = fastPtr->next->next;
      }
      slowPtr = slowPtr->next;
    }
    return 0;
  } else {
    return 0;
  }
}


struct SinglyLinkedList * add_SinglyLinkedList(struct SinglyLinkedList *this, struct String *val) {
  if (this->hp == NULL) {
    this->tp = newSLLNode(val);
    this->hp = this->tp;
  } else {
    this->tp->next = newSLLNode(val);
    this->tp = this->tp->next;
    this->size += 1;
  }
  return this;
}

struct SLLNode * reverse_SinglyLinkedListHelper(struct SinglyLinkedList *this, struct SLLNode *next) {
  if (next->next == NULL) {
    this->hp = next;
    return next;
  } else {
    SLLNode *previous = reverse_SinglyLinkedListHelper(this, next->next);
    previous->next = next;
    next->next = NULL;
    return next;
  }
}

void reverse_SinglyLinkedList(struct SinglyLinkedList *this) {
  SLLNode *reversedTail = reverse_SinglyLinkedListHelper(this, this->hp);
  this->tp = reversedTail;
}


void sort_Int_SinglyLinkedList(struct SinglyLinkedList *this) {
  SLLNode *prevFringe = NULL;
  SLLNode *insFinder = this->hp;
  SLLNode *fringe = this->hp;
  int hasFoundInsertion = 0;
  while (fringe != NULL) {
    SLLNode *prevIns = NULL;
    while (insFinder != fringe && !hasFoundInsertion) {
      if (compareIntString(insFinder->val, fringe->val)) {
	SLLNode *tmp = fringe->next;
	fringe->next = insFinder;
	if (prevFringe != NULL) {
	  prevFringe->next = tmp;
	}
	if (prevIns == NULL) {
	  this->hp = fringe;
	  
	} else {
	  prevIns->next = fringe;
	}	
	fringe = tmp;
	hasFoundInsertion = 1;
      } else {
	if (prevIns != NULL) {
	  prevIns = prevIns->next;
	} else {
	  prevIns = this->hp;
	}
	insFinder = insFinder->next;
      }
    }
    insFinder = this->hp;
    if (!hasFoundInsertion) {
      if (prevFringe == NULL) {
	prevFringe = this->hp;
      } else {
	prevFringe = prevFringe->next;
      }
      fringe = fringe->next;
    }
    hasFoundInsertion = 0;
  }
}

struct DoublyLinkedList * add_DoublyLinkedList(struct DoublyLinkedList *this, struct String *val) {
  if (this->hp == NULL) {
    this->tp = newDLLNode(val);
    this->hp = this->tp;
  } else {
    this->tp->next = newDLLNode(val);
    this->tp = this->tp->next;
    this->size += 1;
  }
  return this;
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
  newList->reverse = &reverse_SinglyLinkedList;
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
