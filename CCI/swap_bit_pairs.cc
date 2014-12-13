/*
  Write a program to swap odd and evens bits in an integer with as few
  instructions as possible (eg. bit 0 and bit 1 are swapped, bit 2 and bit 3
  are swapped, etc.)
*/

#include <assert.h>

int swapBitPairs(int n) {
  int which_evens_on = (n << 1) & 0xAAAAAAAA;
  int which_odds_on = (n >> 1) & 0x55555555;
  return which_evens_on | which_odds_on;
}

int main() {
  // 100111001010 to 011011000101
  assert(swapBitPairs(2506) == 1733);
}
