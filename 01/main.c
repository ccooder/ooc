#include <stdio.h>

#include "new.h"
#include "Object.h"
#include "Set.h"

int main() {
  void *s = new(Set);
  void *s1 = new(Set);
  void *a = add(s, new(Object));
  void *b = add(s, new(Object));
  void *c = add(s1, new(Object));

  printf("set count:%d\n", count(s));

  if (contains(s, a) && contains(s, b))
    puts("ok");

  if (contains(s, c))
    puts("contains?");

  if (contains(s, a))
    puts("contains");

  if (differ(a, add(s, a)))
    puts("differ?");

  if (contains(s, drop(s, a)))
    puts("drop?");

  delete(drop(s, b));
  delete(drop(s, c));

  return 0;
}

