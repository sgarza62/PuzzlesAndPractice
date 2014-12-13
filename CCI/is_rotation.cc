// Assume you have a method isSubstring which checks if one word is a substring
// of another. Given two strings, s1 and s2, write code to check if s2 is a
// rotation of s1 using only one call to isSubstring(e.g., "waterbottle" is a
// rotation of "erbottlewat").

#include <iostream>
#include <string>

bool isSubstring(std::string s1, std::string s2) {
  if (s1.find(s2) != std::string::npos) return true;
  else return false;
}

bool isRotation(std::string s1, std::string s2) {
  if (s1.size() != s2.size()) return false;

  // 'erbottlewaterbottlewat' == 'erbottle' + 'waterbottle' + 'wat'
  std::string str_doubled = s1 + s1;
  if (isSubstring(str_doubled, s2)) return true;
  else return false;
}

int main() {
  // Test 1 (example)
  std::string word = "waterbottle";
  std::string rotated = "erbottlewat";
  std::cout << word << ", " << rotated;
  if (isRotation(word, rotated)) std::cout << " (true) OK" << std::endl;
  else std::cout << " (false) ERROR" << std::endl;

  // Test 2 (extra chars on a rotation)
  word = "waterbottle";
  rotated = "erbottlewater";
  std::cout << word << ", " << rotated;
  if (isRotation(word, rotated)) std::cout << " (true) ERROR" << std::endl;
  else std::cout << " (false) OK" << std::endl;

  
  // Test 3 (not rotation)
  word = "bad";
  rotated = "cab";
  std::cout << word << ", " << rotated;
  if (isRotation(word, rotated)) std::cout << " (true) ERROR" << std::endl;
  else std::cout << " (false) OK" << std::endl;
}

// mv to is_rotation.cc
