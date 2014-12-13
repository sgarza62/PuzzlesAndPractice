// Implement a function which reverses a null-terminated string in place.

#include <iostream>

void reverse(char* str) {
  if (*str) {
    char* end = str; // initialize the end ptr at the beginning
    while (*end) {
      ++end;
    }
    --end; // decrement the ptr to point to last char before /0

    char temp;
    while (str < end) {
      temp = *str;
      *str = *end;
      *end = temp;
      ++str;
      --end;
    }
  }
}

int main() {
  char s[] = "hello";
  reverse(s);
  std::cout << s << std::endl;
}
