#include <iostream>

#include "IntArray.h"

struct IntArray {
  int n;
  int* elements;
};

IntArray* Create(int length) {
  IntArray* A = new IntArray;
  A->n = length;
  A->elements = new int[A->n];

  for (int i = 0; i < A->n; i++) setElement(A, i, 0);

  return A;
}

void Destroy(IntArray* A) {
  delete[] A->elements;
  delete A;
}

int getLength(IntArray* A) { return A->n; }

int getElement(IntArray* A, int index) { return A->elements[index]; }

void setElement(IntArray* A, int index, int value) {
  A->elements[index] = value;
}

void printArray(IntArray* A) {
  for (int i = 0; i < getLength(A); i++) {
    std::cout << A->elements[i] << " ";
  }
  std::cout << std::endl;
}

void pushBack(IntArray* A, int value) {
  int lengthA = getLength(A);
  int i = 0;

  while (getElement(A, i) != 0 && i < lengthA) {
    i++;
  }

  if (i == getLength(A)) {
    resize(A, lengthA + 1);
  }

  setElement(A, i, value);
}

void resize(IntArray* A, int newLength) {
  IntArray* B = new IntArray;
  B->n = newLength;
  B->elements = new int[B->n];

  for (int i = 0; i < A->n; i++) setElement(B, i, getElement(A, i));

  delete[] A->elements;
  A->n = B->n;
  A->elements = B->elements;
  delete B;
}