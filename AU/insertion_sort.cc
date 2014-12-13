/*
  Pages 35-40.

  For each index p from 0 to n, insertion sort right-shifts all elements in subarray [0:p] that are greater than the element at p. The value at p is then copied to the index left of the shifted elements.

  T = O(n^2)
  Approaches O(n) when array is already sorted.

  1. for i in range(0, n):
      A. val = arr[i];
      B. j = i-1;
      C. while (j >= 0) and (arr[j] > val):
          arr[j+1] = arr[j];
	  j--;
      D. arr[j] = val;


  NOTES:
  - Insertion sort is great when the array is sorted, or almost sorted (so long
    as the elements to be moved aren't too far from there desired location.
  - If moving elements is an expensive operation, then insertion sort loses, b/c
    of how many elements are shifted in the inner loop.
*/

#include <assert.h>
#include "sorting_helpers.h"

void insertion_sort(int *arr, int start, int length) {
  int val, j;

  for (int i=1; i<length; i++) {
    val = arr[i];
    j = i-1;
    
    while ((j >= 0) && (arr[j] > val)) {
      arr[j+1] = arr[j];
      j--;
    }

    arr[j+1] = val;
  }
}

int main() {
  run_tests(insertion_sort);
  return 0;
}
