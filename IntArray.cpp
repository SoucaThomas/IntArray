#include "IntArray.h"

#include <iostream>

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
    // resize(A, lengthA + 1);
    IntArray* B = new IntArray;
    B->n = getLength(A) + 1;
    B->elements = new int[B->n];

    for (int i = 0; i < A->n; i++) setElement(B, i, getElement(A, i));

    setElement(B, A->n, value);

    // Delete old A's elements array
    delete[] A->elements;

    // Copy B's data to A
    A->n = B->n;
    A->elements = B->elements;

    // Delete B structure (but not its elements, since A now owns them)
    delete B;
  }

  setElement(A, i, value);
}

// void resize(IntArray* A, int newLength) {
//   int* newElements = new int[newLength];
//   for (int i = 0; i < getLength(A); i++) {
//     newElements[i] = getElement(A, i);
//   }

//   delete[] A->elements;
//   A->elements = newElements;
//   A->n = newLength;
// }
