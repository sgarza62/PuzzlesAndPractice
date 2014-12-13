// Implement a queue MyQueue using only 2 stacks

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



class MyQueue {
  Stack sorted, hold;

public:
  void PushBack(int i) {
    int el;
    if (!hold.IsEmpty()) hold.Pop(); // remove old copy of Last-In

    // fill <hold> with preexisting elements in reverse order...
    while (!sorted.IsEmpty()) {
      el = sorted.Peek();
      sorted.Pop();
      hold.Push(el);
    }

    // put new element at the bottom of the pile...
    sorted.Push(i);

    // fill <sorted> with preexisitng elements so FI elements are on top
    while (!hold.IsEmpty()) {
      el = hold.Peek();
      hold.Pop();
      sorted.Push(el);
    }

    // make a copy of Last-In, since it's at the bottom of <sorted>
    hold.Push(i); 
  };

  void PopFront() {sorted.Pop();};

  int FirstIn() {return sorted.Peek();};

  int LastIn() {return hold.Peek();};
};


int main() {
  MyQueue q;
  int a[10] = {5, 10, 1, 15, 2, 20, 4, 13, 8, 11};

  for (int i=0; i<10; i++) {
    q.PushBack(a[i]);
    std::cout << "Pushing " << a[i] << ". FI(" << q.FirstIn() << "). LI("
	      << q.LastIn() << ")." << std::endl;
  }

  for (int i=0; i<10; i++) {
    std::cout << "Popping " << q.FirstIn() << ". FI(" << q.FirstIn() << "). LI("
	      << q.LastIn() << ")." << std::endl;
    q.PopFront();
  }  
}
