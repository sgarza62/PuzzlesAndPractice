/*
  Pages 49-57.

  Quick sort recursively sorts an array in place, by considering it sorted when
  it's 0 or 1 elements. Otherwise, it partitions the array by choosing some
  PIVOT element and swapping it so that all elements <= to it are to its LEFT
  and all elements > are to its RIGHT. The LEFT and RIGHT subarrays are then
  quick sorted.

  T = O(n^2)
  Though with a randomized pivots, T is usually O(n*lg(n)).

  NOTES:
  - Quick sort carries very small constants. In practice, it can be very fast.
  - If the pivot isn't well selected, or if the array isn't in random order,
    then quicksort can run in O(n^2).
 */

#include "sorting_helpers.h"

using namespace std;


int partition(int *arr, int start, int end) {
  int l = start - 1;
  int r = start;
  int p = end - 1;

  for (;r<p; r++) {
    if (arr[r] <= arr[p]) {
      swap(arr, r, l+1);
      l++;
    }
  }

  swap(arr, p, l+1);
  return l+1;
}  


void quick_sort(int *arr, int start, int end) {
  if (end - start <= 1) return;
  int part = partition(arr, start, end);
  quick_sort(arr, start, part);
  quick_sort(arr, part+1, end);
}

int main() {
  run_tests(quick_sort);
  return 0;
}
