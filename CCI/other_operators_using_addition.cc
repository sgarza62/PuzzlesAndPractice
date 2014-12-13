/*
  Implement multiplication, substraction, and division functions using only the
  addition operator.
*/

#include <assert.h>

int multiplication(int a, int b) {
  int product = 0;
  for (int i=0; i<b; i++) {
    product += a;
  }
  return product;
}


int subtraction(int a, int b) {
  int difference = 0;
  for (int i=b; i<a; i++) {
    difference++;
  }
  return difference;
}


int division(int a, int b) {
  int quotient = 0;
  for (int i=0; i<a; i+=b) {
    quotient++;
  }
  return quotient;
}


int main() {
  assert(multiplication(8, 4) == 32);
  assert(multiplication(4, 8) == 32);

  assert(subtraction(43, 6) == 37);
  assert(subtraction(5, 5) == 0);

  assert(division(32, 8) == 4);
  assert(division(32, 4) == 8);
}
