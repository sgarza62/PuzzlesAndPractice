// Write a function to check if the value of a binary number (passed in as a
// string) equals the hexadecimal representation of a string.

/*
  With this problem, we're trying to demonstrate code reuse.

  BREAKING DOWN THE PROBLEM:
  The most obvious approach to this problem is to find the values of the two
  numbers in a common base. Base 10 works fine. So, we'll have to convert each
  digit to base 10, then convert the whole number to base 10, then compare.

  Overview of numbers:
  Numbers can be expressed in any base, so long as the base is at least 2, and
  we at least base number characters to represent digits. 

  Numbers have multiple digits. These digits represent different values, based
  on their "place". The digit in the rightmost place represents the value:
  digit * (base ^ 0)
  The second digit over from the right represents:
  digit * (base ^ 1)
  The third digit over from the right represents:
  digit * (base ^ 2)
  and so on...

  QUICK TESTS:

  CLARIFYING QUESTIONS TO ASK:
*/

#include <iostream>
#include <string>
#include <math.h>

int charToValue(char c) {
  // PSEUDOCODE:
  // Must find the ASCII decimal representation of c.
  // if number (ie, b/w 0 and 9): c - '0'
  // A - F  =  65 - 70
  // we want A at 10, so c - 'A' + 10
  // a - f  =  97 - 102
  // we want a at 10, so c - 'a' + 10
  if (c >= '0' && c <= '9')  return c - '0';
  if (c >= 'A' && c <= 'F')  return c - 'A' + 10;
  if (c >= 'a' && c <= 'f')  return c - 'a' + 10;
  return -1;
}

int convertFromBase(std::string n, int base) {
  // PSEUDOCODE:
  // check that base is allowed (2-10, 16)
  // iterate through places, from last to first:
  // convert char to digit (in the case of base 16)
  // digit * (base ^ i)
  // all the time adding to total value
  if (base < 2 || (base > 10 && base != 16))  return -1;

  int value = 0;
  for (int i=n.length()-1; i>=0; i--) {
    char c = n[i];
    int dig = charToValue(c);
    if (dig == -1)  return -1;
    int exp = n.length() - 1 - i;
    value += dig * pow(base, exp);
  }
  return value;
}

bool compareBinToHex(std::string bin, std::string hex) {
  // PSEUDOCODE:
  // convert bin to dec1
  // convert hex to dec2
  // return dec1 == dec2
  int n1 = convertFromBase(bin, 2);
  int n2 = convertFromBase(hex, 16);

  if (n1 < 0 || n2 < 0)  return false;
  else  return (n1 == n2);
}

int main() {
  std::cout << "Expect T:     (100, 4): "
	    << compareBinToHex("100", "4") << std::endl;

  std::cout << "Expect T:  (10100, 14): "
	    << compareBinToHex("10100", "14") << std::endl;

  std::cout << "Expect T:  (11111, 1F): "
	    << compareBinToHex("11111", "1F") << std::endl;

  std::cout << "Expect F:     (101, 4): "
	    << compareBinToHex("101", "4") << std::endl;

  std::cout << "Expect F:  (10100, 15): "
	    << compareBinToHex("10100", "15") << std::endl;

  std::cout << "Expect F:     (20, 14): "
	    << compareBinToHex("20", "14") << std::endl;

  std::cout << "Expect F:  (11111, AA): "
	    << compareBinToHex("11111", "AA") << std::endl;      
  return 0;
}
