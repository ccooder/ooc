//
// Created by King on 2023/6/8.
//

#ifndef OOC_02_NEW_H_
#define OOC_02_NEW_H_
#include <stdio.h>
#include <stdarg.h>

void *new(const void *_class, ...);
void *clone(const void *self);
void delete(void *self);
int differ(const void *self, const void *b);
size_t sizeOf(const void *self);

#endif //OOC_02_NEW_H_
