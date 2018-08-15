#include <stdlib.h>
#include "Util.h"
#pragma once

typedef struct BinaryTree {
  int val;
  struct BinaryTree *left;
  struct BinaryTree *right;
} BinaryTree;

struct BinaryTree *newBinaryTree(int val);

int height(struct BinaryTree *this) {
  if (this == NULL) {
    return 0;
  }
  return max(height(this->left), height(this->right)) + 1;
}

int isBalanced(struct BinaryTree *this) {
  if (this == NULL) {
    return 1;
  }
  
   return abs(height(this->left) - height(this->right)) < 2 && isBalanced(this->right) && isBalanced(this->left);
}

void insert_BinaryTreet(struct BinaryTree *this, int val) {
  BinaryTree *iter = this;
  BinaryTree *prev = NULL;
  while(iter != NULL) {
    prev = iter;
    if (val < iter->val) {
      iter = iter->left;
    } else {
      iter = iter->right;
    }
  }

  if (prev->left == NULL) {
    prev->left = newBinaryTree(val);
  } else {
    prev->right = newBinaryTree(val);
  }
}

struct BinaryTree *newBinaryTree(int val) {
  BinaryTree * ptr = malloc(sizeof(BinaryTree));
  ptr->val = val;
  ptr->left = NULL;
  ptr->right = NULL;
  return ptr;
}






