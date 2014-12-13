/*
  Pages 40-41.

  Merge sort uses a divide-and-conquer approach, by dividing subarrays and
  recursively sorting them (w/ base case being size 0 or 1), then merging the
  sorted subarrays back into the original array.

  T = O(n * lg(n))
  T = o(n * lg(n))

  MERGESORT(arr, START, END):           // START incl; END excl
  1. if (END-START <= 1): return;
  2. else:
      A. MID = START + ((END - START + 1) / 2);
      B. MERGESORT(arr, START, MID);
      C. MERGESORT(arr, MID, END);
      D. MERGE(arr, START, MID, MID, END);
      E. return;

  MERGE(arr, Astart, Aend, Bstart, Bend):
  1. Copy arrays of A and B, each appended with MAXINT (sentinels).
  2. a = Astart; b = Bstart;
  3. for i in range(0, size(A)+size(B)):
      A. if (A[a] <= B[b]):
          a. arr[Astart+i] = A[a];
	  b. a++;
      B. else:
          a. arr[Astart+i] = B[b];
	  b. b++;


*/

#include <limits.h>
#include "sorting_helpers.h"

using namespace std;


void merge(int *arr, int s1, int e1, int s2, int e2) {
  int A[e1-s1+1];
  int B[e2-s2+1];

  for (int i=0; i<e1-s1; i++) A[i] = arr[s1+i];
  for (int j=0; j<e2-s2; j++) B[j] = arr[s2+j];
  A[e1-s1] = INT_MAX;
  B[e2-s2] = INT_MAX;
  
  int a = 0;
  int b = 0;
  for (int k=s1; k<e2; k++) {
    if (A[a] <= B[b]) {
      arr[k] = A[a];
      a++;
    } else {
      arr[k] = B[b];
      b++;
    }
  }
}



void merge_sort(int *arr, int start, int end) {
  if (end - start <= 1) return;

  int mid = start + ((end - start + 1) / 2);
  merge_sort(arr, start, mid);
  merge_sort(arr, mid, end);
  merge(arr, start, mid, mid, end);
  return;
}


int main() {
  run_tests(merge_sort);
  return 0;
}
