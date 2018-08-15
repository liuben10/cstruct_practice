#include "HashMap.h"

int main() {
  HashMap *newMap = newHashMap();
  String *toHash = fromCharBuf("hello world", 11);
  int something = 3;
  newMap->put(newMap, toHash, &something);
  int *retrieved = (int *)newMap->get(newMap, toHash);
  printf("retrieved=%d\n", *retrieved);
}
