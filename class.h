#include <stdlib.h>
#pragma once

#define CLASS(T)					\
  struct T *new_##T() {					\
    T *result = malloc(sizeof(T));			\
    result->this = result;				\
    result->new = &new_##T;				\
    return result;					\
  }
