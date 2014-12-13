// Sort a stack, biggest items on top, using at most one other stack.

#include <iostream>
#include <stdexcept>
#include <vector>

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
};



void Sort(Stack* s1) {
  Stack s2;

  while (!s1->IsEmpty()) {
    int i = s1->Peek();
    s1->Pop();

    if (s2.IsEmpty()) {
      s2.Push(i);
      continue;
    }

    while (true) {
      if (i <= s2.Peek() || s2.IsEmpty()) {
	s2.Push(i);
	break;
      } else {
	s1->Push(s2.Peek());
	s2.Pop();
      }
    }
  }

  while (!s2.IsEmpty()) {
    s1->Push(s2.Peek());
    s2.Pop();
  }
}



int main() {
  Stack s;
  int a[] = {5, 2, 10, 2, 1, 2, -51, -5, 40, 100};

  for (int i=0; i<10; i++) {
    s.Push(a[i]);
    std::cout << "Pushed " << a[i] << ", top is " << s.Peek() << std::endl;
  }

  Sort(&s);

  int top;
  while (!s.IsEmpty()) {
    top = s.Peek();
    s.Pop();
    std::cout << "Popped " << top << std::endl;
  }
}
