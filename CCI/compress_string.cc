// Implement a method to perfomr basic string compression using the counts of
// repeated characters. For example, the string aabccccaaa would become a2b1c5a3
// If the compressed string would not become smaller than the original string,
// your method should return the original string. Assume the string has only
// alphabetic characters.

#include <iostream>
#include <sstream>
#include <string>

std::string compressString(std::string str) {
  std::stringstream ss;
  int count = 0;

  for (int i=0; i<str.size(); i++) {
    count++;
    if (str[i] != str[i+1]) {
      ss << str[i] << count;
      count = 0;
    }
  }

  std::string compressed = ss.str();
  if (compressed.size() < str.size()) return compressed;
  else return str;
}

int main() {
  std::string s1 = "aabcccccaaa";
  std::cout << s1 << std::endl;
  std::cout << compressString(s1) << std::endl;

  std::string s2 = "I wish I had cheese right nowww! Oh well I guess I don't";
  std::cout << s2 << std::endl;
  std::cout << compressString(s2) << std::endl;

  std::string s3 = "abcdefg hijklmnop qrstuvw xyz";
  std::cout << s3 << std::endl;
  std::cout << compressString(s3) << std::endl;
}
