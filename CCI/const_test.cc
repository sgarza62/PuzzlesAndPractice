#include <iostream>

int main() {
  const int x = 10;
  int y = x;
  std::cout << y << " " << x << std::endl;
  y++;
  std::cout << y << " " << x << std::endl;

  int z = 10;
  int a = z;
  std::cout << a << " " << z << std::endl;
  a++;
  std::cout << a << " " << z << std::endl;
}
