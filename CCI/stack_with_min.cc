// Implement a stack, where Push(), Pop(), and GetMin() are all O(1) Time.

#include <iostream>
#include <stdexcept>
#include <vector>

class Node {
  int data;
  int prev_min;

public:
  void SetData(int d) {data=d;};
  int GetData() {return data;};
  void SetPrevMin(int m) {prev_min=m;};
  int GetPrevMin() {return prev_min;};
};
  

class StackWithMin {
  int stack_min = -1;
  std::vector<Node*> stack;

public:
  bool IsEmpty() {return (stack.empty());};

  Node* Peek() {
    if (IsEmpty()) return nullptr;
    else return stack.back();
  };

  void Push(int d) {
    Node* n = new Node;
    n->SetData(d);
    n->SetPrevMin(stack_min);

    if (IsEmpty()) stack_min = d;
    else stack_min = (d<stack_min ? d : stack_min);

    stack.push_back(n);
  };

  void Pop() {
    if (IsEmpty()) throw std::out_of_range("Empty stack can't be popped.");

    Node* n = stack.back();
    stack.pop_back();
    stack_min = n->GetPrevMin();
    delete n;
  };

  int GetMin() {return stack_min;};
};

  
int main() {
  StackWithMin s;
  int a[] = {5, 10, 1, 0, -51, 500, 11, 13, 2, 1, 2, 2, 14};

  for (int i=0; i<13; i++) {
    s.Push(a[i]);
    std::cout << "Pushed " << a[i] << ", min is " << s.GetMin() << std::endl;
  }

  int top;
  while (!s.IsEmpty()) {
    top = s.Peek()->GetData();
    s.Pop();
    std::cout << "Popped " << top << ", min is " << s.GetMin() << std::endl;
  }
}
