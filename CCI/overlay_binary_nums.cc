/*
  You are given two 32-bit numbers, N and M, and two positions, i and j.
  Write a method to insert M into N such that M starts at bit j and ends at
  bit i.
  You can assume that bits j through i have enough space to fit all of M.
  
  EXAMPLE:
  Input: N = 10000000000, M = 10011, i = 2, j = 6
  Output: 10001001100
*/

#include <assert.h>

// We can achieve this by, first clearing the target bits in <base>, then
// shifting <overlay> left <start> bits, and finally ORing the two to update
// the target bits.

int bitOverlay(int base, int overlay, int start, int stop) {
  // clear relevant bits
  int cleared_base = base & ~((1 << (start - stop)) << start);
  // update relevant bits
  return cleared_base | (overlay << start);
}

int main() {
  int x = bitOverlay(1024, 19, 2, 6); // 10000000000, 10011, 2, 6
  assert(x == 1100); // 10001001100
}
