/*
  Quick/Insertion hybrid, where insertion takes over if a recursive sort call
  is made on a subarray of size <= 17.
*/

#include "sorting_helpers.h"

using namespace std;


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


void santi_sort(int *arr, int start, int end) {
  if (end - start <= 17) insertion_sort(arr, start, end);
  else {
      int part = partition(arr, start, end);
      santi_sort(arr, start, part);
      santi_sort(arr, part+1, end);
  }
}


int main() {
  run_tests(santi_sort);
  return 0;
}
