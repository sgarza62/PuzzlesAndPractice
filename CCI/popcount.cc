/*
  Write a function that counts the number of set bits in a number.
*/

#include <assert.h>

long popcount(long n) {
  unsigned int c; // count
  for (c=0; n; c++) {
    n &= n - 1;
  }
  return c;
}
int main() {
  // n = 011011101111001
  // n = n & (n - 1)

  // Values of n before each iteration:
  // 011011101111001
  // 011011101111000
  // 011011101110000
  // 011011101100000
  // 011011101000000
  // 011011100000000
  // 011011000000000
  // 011010000000000
  // 011000000000000
  // 010000000000000
  // 000000000000000
  assert(popcount(14201) == 10);  // 011011101111001
}
