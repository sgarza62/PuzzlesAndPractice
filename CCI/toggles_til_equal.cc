/*
  Write a function to determine the number of bits you would need to flip to
  convert interger a to integer b.
*/

#include <assert.h>

int togglesTilEqual(int a, int b) {
  int toggles_set = a ^ b;
  int c;
  for (c=0; toggles_set; c++) {
    toggles_set &= toggles_set - 1;
  }
  return c;
}

int main() {
  // a = 11101, b = 01111
  assert(togglesTilEqual(29, 15) == 2);

  // a = 111000101011, b = 011011101010
  assert(togglesTilEqual(3627, 1770) == 4);
}
