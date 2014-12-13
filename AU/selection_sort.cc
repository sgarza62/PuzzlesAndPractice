/*
  Pages 32-35.

  For each index p from 0 to n, selection sort finds the minimum element in the
  subarray [p:n], and swaps with element at p. 

  T = tight bound n^2

  1. for i in range(n-1):
      A. SMALLEST = i;
      B. for j in range(i+1, n):
          a. if (arr[j] < arr[SMALLEST]) SMALLEST = j;
      C. swap(arr, i, SMALLEST);

  NOTES:
  - Selection sort will always operate in O(n^2) time; however, it only moves n
    elements (because elements are swapped, not shifted). This means that, if
    for whatever reason, moving elements is an expensive operation, selection
    sort *might* be a good option.
*/

#include <assert.h>
#include "sorting_helpers.h"


void selection_sort(int *arr, int start, int length) {
  int smallest;
  for (int i=0; i<length-1; i++) {
    smallest = i;
    for (int j=i+1; j<length; j++) {
      if (arr[j] < arr[smallest]) smallest = j;
    }
    swap(arr, smallest, i);
  }
}


int main() {
  run_tests(selection_sort);
  return 0;
}
