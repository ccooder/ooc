//
// Created by King on 2023/6/8.
//
#include "new.h"
#include <stdlib.h>
#include <assert.h>
#include "new.r"

void *new(const void *_class, ...) {
  const struct Class *class = _class;
  void *p = calloc(1, class->size);
  assert(p);
  *(const struct Class **) p = class;
  if (class->ctor) {
    va_list ap;
    va_start(ap, _class);
    p = class->ctor(p, &ap);
    va_end(ap);
  }
  return p;
}

void *clone(const void *self) {
  const struct Class * const *cp = self;
  assert(self && *cp && (*cp)->clone);
  return (*cp)->clone(self);
}

void delete(void *self) {
  const struct Class **cp = self;
  if (self && *cp && (*cp)->dtor) {
    self = (*cp)->dtor(self);
    free(self);
  }
}

int differ(const void *self, const void *b) {
  const struct Class * const * cp = self;
  assert(self && *cp && (*cp)->diff);
  return (*cp)->diff(self, b);
}

size_t sizeOf(const void *self) {
  const struct Class * const *cp = self;
  assert(self && *cp);
  return (*cp)->size;
}
