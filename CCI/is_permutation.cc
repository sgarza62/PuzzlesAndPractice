// Given two strings, write a method to decide if one is a permutation of the other

#include <string>
#include <iostream>

bool isPermutation(std::string s, std::string t) {
  if (s.size() != t.size()) return false;

  // Indices correspond to ASCII, and elements correspond to occurrences
  int occ[256] = {0};

  // Count occurrences in s
  for (char c : s) occ[int(c)]++;

  // Count occurrences in t
  for (char c : t) {
    if (occ[int(c)] <= 0) return false; // more occ in t than in s
    else occ[int(c)]--;
  }

  for (int i : occ) {
    if (i != 0) return false; // more occ in s than in t
  }
  return true;
}


int main() {
  std::string s = "there is a god";
  std::string t = "the dog is ear";
  std::string u = "not his rear!";
  std::string v = "god, dija hear";

  std::cout << "T: " << isPermutation(s, t) << std::endl;
  std::cout << "T: " << isPermutation(s, s) << std::endl;
  std::cout << "F: " << isPermutation(s, u) << std::endl;
  std::cout << "F: " << isPermutation(s, v) << std::endl;
  std::cout << "F: " << isPermutation(t, v) << std::endl;
}
