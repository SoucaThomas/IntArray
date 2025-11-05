#include <iostream>

#include "IntArray.cpp"
#include "IntArray.h"

using namespace std;

int main() {
  IntArray* A = Create(7);
  setElement(A, 0, 2);
  setElement(A, 1, 1);
  setElement(A, 2, 5);
  setElement(A, 4, 11);
  setElement(A, 5, 8);
  setElement(A, 6, 9);

  IntArray* B = A;

  printArray(A);

  // printArray(B);

  pushBack(A, 13);

  printArray(A);

  pushBack(A, 134);

  printArray(A);

  pushBack(A, 13879);

  printArray(A);

  setElement(A, 8, 146);

  printArray(A);

  Destroy(A);

  // printArray(B);
  return 0;
}