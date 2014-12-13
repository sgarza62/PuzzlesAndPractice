/*
  Pages 28-32.

  Binary search checks the middle element of a sorted array, returning the index
  if the element is found; if element is not found, it checks the appropriate
  half-sized subarray. If the subarray is ever of size 0, we know the element is
  not present in the list.

  T = O(lg(n)).

  1. START = 0; END = n-1;
  2. while START <= END:
      A. MID = floor((START + END) / 2);
      B. if    (MID == KEY):     return MID;
      C. elif  (arr[MID] > KEY): END = MID - 1;
      D. elif  (arr[MID] < KEY): START = MID + 1;
  3. return NOTFOUND;
*/

#include <assert.h>

// Expects sorted array. Returns index of the found element, or -1 if not found.
int binary_search(const int *arr, int length, int sought) {
  int start = 0;
  int end = length - 1;
  int mid;

  while (start <= end) {
    mid = (start + end) / 2;

    if (arr[mid] == sought) {
      return mid;
    } else if (sought < arr[mid]) {
      end = mid - 1;
    } else if (sought > arr[mid]) {
      start = mid + 1;
    }
  }

  return -1;
}

// Tests.
int main() {
  int empty[0] = {};
  int oneelement_present[1] = {42};
  int oneelement_missing[1] = {43};
  int elevenelement_present[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  int elevenelement_missing[11] = {1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12};
  
  assert(binary_search(empty, 0, 42) == -1);
  assert(binary_search(oneelement_present, 1, 42) == 0);
  assert(binary_search(oneelement_missing, 1, 42) == -1);
  assert(binary_search(elevenelement_present, 11, 6) == 5);
  assert(binary_search(elevenelement_missing, 11, 6) == -1);

  return 0;
}
