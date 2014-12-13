#include <assert.h>
#include <iostream>

using namespace std;

void print_array(int*arr, int length) {
  for (int i=0; i<length; i++) cout << arr[i] << " ";
  cout << endl;
}

bool is_sorted(int *arr, int length) {
  if (length > 1) {
    for (int i=0; i<length-1; i++) if (arr[i] > arr[i+1]) return false;
  }
  return true;
}

void run_tests(void (*sorting_func)(int*, int, int)) {
  int empty[0] = {};
  int one_element[1] = {42};  
  int already_sorted[6] = {-1, 0, 1, 2, 5, 10};
  int random_order[6] = {42, 6, -101, -102, 12, 0};
  int reverse_order[6] = {10, 5, 2, 1, 0, -1};

  int *arrays[] = {
    empty,
    one_element,
    already_sorted,
    random_order,
    reverse_order,
  };

  int sizes[5] = {0, 1, 6, 6, 6};
  
  for (int i=0; i<5; i++) {
    print_array(arrays[i], sizes[i]);
    (*sorting_func)(arrays[i], 0, sizes[i]);
    print_array(arrays[i], sizes[i]);
    assert(is_sorted(arrays[i], sizes[i]));
    cout << endl;
  }
}


void swap(int *arr, int a, int b) {
  int tmp = arr[a];
  arr[a]  = arr[b];
  arr[b]  = tmp;
}
