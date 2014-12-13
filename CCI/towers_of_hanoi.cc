// Write a program that solves the Towers of Hanoi problem for N disks,
// using stacks.

#include <iostream>
#include <vector>
#include <stdexcept>

/* Dynamic-Array implementation with element-type <int> */
class Stack {
  std::vector<int> stack;

public:
  int GetSize() {return stack.size();};

  bool IsEmpty() {return (stack.empty());};

  int Peek() {
    if (this->IsEmpty()) return -9999;
    else return stack.back();
  };

  void Push(int d) {
    stack.push_back(d);
  };

  void Pop() {
    if (this->IsEmpty()) throw std::out_of_range("Empty stack can't be popped.");
    stack.pop_back();
  };

  void Print() {
    for(std::vector<int>::const_iterator i=stack.begin(); i!=stack.end(); ++i) {
      std::cout << *i << ' ';
    }
    std::cout << std::endl;
  };
};


class Hanoi {
  Stack s1, s2, s3;
  Stack* all[3];
  int height;

public:
  Hanoi(int h=10) {
    height = h;
    CreateFirstStack(height);
    all[0] = &s1;
    all[1] = &s2;
    all[2] = &s3;
  };

  void CreateFirstStack(int h) {
    for (int i=h; i>0; i--) {
      s1.Push(i);
    }
  };

  void Solve(int h=-99999, int start=0, int use=1, int end=2) {
    int disk;
    if (h==-99999) h = height;
    if (h==0) return;
    if (h==1) {
      disk = all[start]->Peek();
      all[start]->Pop();
      all[end]->Push(disk);
      return;
    } else {
      // move h-1 from START to USE
      Solve(h-1, start, end, use);

      // move h from START to END
      disk = all[start]->Peek();
      all[start]->Pop();
      all[end]->Push(disk);

      // move h-1 from USE to END
      Solve(h-1, use, start, end);
    }
  };

  void Print() {
    // TODO: fix to not change towers
    if (height==0) return;
    for (int i=0; i<3; i++) {
      std::cout << i << "] ";
      all[i]->Print();
    }
    std::cout << std::endl;
  }
};


int main() {
  int d = 20;
  Hanoi han(d);
  han.Print();

  std::cout << "==";
  for (int i=0; i<d; i++) std::cout << "==";
  std::cout << std::endl;

  han.Solve();
  han.Print();
}
