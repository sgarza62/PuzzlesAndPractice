// Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structures?

#include <iostream>
#include <string>

// T = O(n), S = O(1)
bool containsDuplicates1(std::string s) {
  int unique_chars = 128; // ASCII
  if (s.size() > unique_chars) return true;

  // Array to store occurances, where indices correspond to ASCII decimal values
  bool chars_found[128] = {false};

  for (int i=0; i<s.size(); i++) {
    if (chars_found[int(s[i])]) return true;
    else chars_found[int(s[i])] = true;
  }
  return false;
}

int main() {
  // test containsDuplicates1
  std::string test1 = "This should test to TRUE.";
  std::cout << containsDuplicates1(test1) << std::endl;

  std::string test2 = "False1234 buh.";
  std::cout << containsDuplicates1(test2) << std::endl;
}


// To reduce our space usage, we could use a bit vector. See page 172 of CCI.
