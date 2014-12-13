/*
  getBit
  setBit
  clearBit
  toggleBit
  updateBit
*/

#include <iostream>
#include <assert.h>

// Get the ith bit of a num
bool getBit(int num, int i) {
  return (num & (1 << i)) >> i;
}

// Set the ith bit of a num to 1
int setBit(int num, int i) {
  return num | (1 << i);
}

// Clear the ith bit of anum to 0
int clearBit(int num, int i) {
  int mask = ~(1 << i);
  return num & mask;
}

int toggleBit(int num, int i) {
  return num ^ (1 << i);
}

// To update the ith bit to a specified value, we must first clear the bit,
// then OR a mask with specified value at the ith bit.
int updateBit(int num, int i, int bitval) {
  num = clearBit(num, i);
  int mask = bitval << i;
  return num | mask;
}

int main() {
  // 0000, 1111, 1010, 0101, 0001
  int tests[5] = {0, 15, 10, 5, 1};

  int gets2[5] = {0, 1, 0, 1, 0};

  // 0100, 1111, 1110, 0101, 0101
  int sets2[5] = {4, 15, 14, 5, 5};

  // 0000, 1011, 1010, 0001, 0001
  int clears2[5] = {0, 11, 10, 1, 1};

  // 0100, 1011, 1110, 0001, 0101
  int toggles2[5] = {4, 11, 14, 1, 5};

  // 0000, 1011, 1010, 0001, 0001
  int updates2_0[5] = {0, 11, 10, 1, 1};

  // 0100, 1111, 1110, 0101, 0101
  int updates2_1[5] = {4, 15, 14, 5, 5};

  for (int i=0; i<5; i++) {
    assert(getBit(tests[i], 2) == gets2[i]);
    assert(setBit(tests[i], 2) == sets2[i]);
    assert(clearBit(tests[i], 2) == clears2[i]);
    assert(toggleBit(tests[i], 2) == toggles2[i]);
    assert(updateBit(tests[i], 2, 0) == updates2_0[i]);
    assert(updateBit(tests[i], 2, 1) == updates2_1[i]);
  }
}
