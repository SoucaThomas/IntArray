#pragma once

#include <limits.h>
#define ERROR INT_MIN

struct IntArray;

IntArray* Create(int initialValue);
void Destroy(IntArray*);

int getElement(IntArray*, int);
void setElement(IntArray*, int, int);
int getLength(IntArray*);

void pushBack(IntArray*, int);
void resize(IntArray*, int);