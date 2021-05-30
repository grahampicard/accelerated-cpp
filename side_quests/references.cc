// Coming from python, pointers and references are a frequent source of
// confusion for me.
//
// The issue is that the concept isn't present in Python, so it can be hard to
// develop an intuiton for it.
//
// To help build the intuition, we need to think about two things: 1. functions
//      2. variable "assignment" and "reference".
//
// In Python, functions take arguments in and output another argument. When we
// pass an argument to a function, python will create a new reference, and
// perform the necessary operations on it. But the underlying value will stay
// the same.
//
// In C++, we can have it both ways. If we want the underlying value to stay the
// same we can pass the argument "int b". This will pass the value, peform an
// operation, and leave the underlying assignment "b = 4" the same. However, if
// we pass a reference, "int& b", this will actually `change` the underlying
// value because we are passing a reference.
//
// A question that comes up for me is does this mean "int" and "int&" are
// differnet data types? In this case, no. They are the same underlying data
// type. The difference is are we providing a "copy" of the data, or the
// original data itself.

#include <iostream>

void adder(int a, int b) {
  std::cout << "(adder1) a, b: " << a << ", " << b << std::endl;
  a = a + 10;
  b = b + 10;
}

void adder2(int a, int& b) {
  std::cout << "(adder2) a, b: " << a << ", " << b << std::endl;
  a = a + 10;
  b = b + 10;
}

int main() {
  int a = 3;
  int b = 4;

  // adder take the value of A and B. This won't affect the underlying
  // value of A or B
  adder(a, b);
  std::cout << "(main) a, b: " << a << ", " << b << std::endl << std::endl;

  // adder takes the value of A and a reference to B. This will affect
  // the underlying value of B, but not A.
  adder2(a, b);
  std::cout << "(main) a, b: " << a << ", " << b << std::endl << std::endl;
}
