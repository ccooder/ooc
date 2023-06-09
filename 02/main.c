//
// Created by King on 2023/6/8.
//
#include "new.h"
#include "String.h"

int main() {
  void *a = new(String, "a");
  void *aa = clone(a);
  void *b = new(String, "b");
  void *c = new(String, "c");
  printf("sizeOf(a) == %zu\n", sizeOf(a));
  if (differ(a, b)) {
    puts("ok");
  }
  if (differ(a, aa)) {
    puts("differ?");
  }
  if (a == aa) {
    puts("clone?");
  }
  delete(a), delete(aa), delete(b);
  return 0;
}