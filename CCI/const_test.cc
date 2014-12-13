#include <iostream>

int main() {
  const int x = 10;
  int y = x;
  std::cout << y << std::endl;
  y++;
  std::cout << y << std::endl;
}
