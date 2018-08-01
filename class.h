#include <stdlib.h>
#pragma once

#define VA_ARGS  __VA_ARGS__

#define THIS(T)					\
  struct T *this;				\

#define NEW(T,...)				\
  struct T *(*new)(__VA_ARGS__);			\
    
#define CLASS(T)				\
  THIS(T)					\
  NEW(T)					\
  

#define BIND(T)						\
  struct T *new_##T() {					\
    T *result = malloc(sizeof(T));			\
    result->this = result;				\
    result->new = &new_##T;				\
    return result;					\
  }
