// Convert a decimal to a binary representation
// (Use a stack)

/*
  APPROACH 1:
  One option is to continually divide the decimal representation, D, by 2, checking all the while if D is odd or even with %2 operaitons. If the initial D (ie, n) is odd, then we know that the last place in the binary representation must be 1; otherwise 0. For example:

  1 = 163 % 2
  --> 162*(2^0) + 1*(2^0)
  1 = 81 % 2
  --> 80*(2^1) + 1*(2^1) + 1*(2^0)
  0 = 40 % 2
  --> 40*(2^2) + 0*(2^2) + 1*(2^1) + 1*(2^0)
  0 = 20 % 2
  --> 20*(2^3) + 0*(2^3) + 0*(2^2) + 1*(2^1) + 1*(2^0)
  0 = 10 % 2
  --> 10*(2^4) + 0*(2^4) + 0*(2^3) + 0*(2^2) + 1*(2^1) + 1*(2^0)
  1 = 5 % 2
  --> 5*(2^5) + 1*(2^5) + 0*(2^4) + 0*(2^3) + 0*(2^2) + 1*(2^1) + 1*(2^0)
  0 = 2 % 2
  --> 2*(2^6) + 0*(2^6) + 1*(2^5) + 0*(2^4) + 0*(2^3) + 0*(2^2) + 1*(2^1) + 1*(2^0)
  1 = 1 % 2
  --> 1*(2^7) + 0*(2^6) + 1*(2^5) + 0*(2^4) + 0*(2^3) + 0*(2^2) + 1*(2^1) + 1*(2^0)
  10100011

  It's important to note that the TO-DO number we're adding on the left of
  our findings is a subproblem * a power of 2. For example, 81 in binary is
  163 in binary --> 10100011
  81 in binary ---> 01010001
  40 in binary ---> 00101000

  163
  =
  (decimalToBinary(81) << 1) + 1(2^0)
  =
  (decimalToBinary(40) << 2) + 1*(2^1) + 1*(2^0)
  ...etc.

  So, basically, we're reducing the problem as we go.


  
  APPROACH 2:
  Let's first take a look at some examples:
  3 = (2^1) + (2^0)            11
  5 = (2^2) + (2^0),           101
  7 = (2^2) + (2^1) + (2^0)    111
  9 = (2^3) + (2^0)            1000

  We can see that, if we find the largest power of 2, 2^P, such that 2^P <= 2,
  we can represent it by putting a 1 in the 2^P's place of our binary number.
  For all places that we skip along the way to 2^0, we place a 0 in their place.
  
  This, of course, requires us to find the largest power of 2, 2^P, such that
  2^P <= 2.

  The naive approach would be something like raising 2 by i, until we find a
  power that is above our decimal representation. We then start at i-1.

  This would require log_2(n) operations for the setup, then log_2(n) operations
  to work our way back down to 2^0.

  A faster approach would be to find it using a log() function.
  For example, with 288, we'd be looking for 8 because 2^8 is 256.
  log(288, 2) would give us 8.16992500144.
  Thus, the highest power of two that is smaller or equal to 288 is 2^8.
  The formula is then: int(log(n, 2)), because the floating points is dropped.
*/

#include <iostream>
#include <sstream>
#include <stack>

// APPROACH 1 (see above)
int decimalToBinary(int dec) {
  std::stack<int> stack;
  while (dec > 0) {
    stack.push(dec % 2);
    dec /= 2;
  }
  
  std::stringstream ss;
  while (!stack.empty()) {
    ss << stack.top();
    stack.pop();
  }

  int binary;
  ss >> binary;
  return binary;
}

int main() {
  for (int i=1; i<20; i++) {
    std::cout << decimalToBinary(i) << std::endl;
  }
}
