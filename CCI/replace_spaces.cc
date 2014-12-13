// Write a function that replaces all spaces in a string with '%20'. You may
// assume that the string has sufficient space at the end to hold additional
// characters, and that you are given the "true" length of the string as input.

#include <iostream>

void replaceSpaces(char* str, int len) {
  int new_len = len;
  for (int i=0; i<len; i++) {
    if (str[i] == ' ') {
      new_len = new_len + 2;
    }
  }

  for (int i=len-1; i>=0; i--) {
    if (str[i] == ' ') {
      str[new_len - 1] = '0';
      str[new_len - 2] = '2';
      str[new_len - 3] = '%';
      new_len = new_len - 3;
    } else {
      str[new_len - 1] = str[i]; // copy char
      new_len--;
    }
  }
}

int main() {
  char s[] = "Hello my name is Santiago.        ";
  std::cout << s << std::endl;
  replaceSpaces(s, 26);
  std::cout << s << std::endl;
}
