// Implement a stack as a resizable array, and as a linked list.

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
};



/* Linked-List implementation with element-type Node*, data type <int> */
class Node {
  int _data;
  Node* _next;

public:
  Node() {};
  void SetData(int d) {_data = d;};
  void SetNext(Node* n) {_next = n;};
  int GetData() {return _data;};
  Node* GetNext() {return _next;};
};


class LLStack {
  int _capacity = 100;
  int _size = 0;
  Node* _head; // latest in

public:
  void Push(int d) {
    if (IsFull()) throw std::out_of_range ("Stack overflow.");

    // attach new node to old head, reassign head to new node
    Node* n = new Node;
    n->SetData(d);
    if (_size == 0) n->SetNext(nullptr);
    else n->SetNext(GetTop());
    _head = n;
    _size++;
  };

  void Pop() {
    if (IsEmpty()) throw std::out_of_range ("Empty stack can't be popped.");

    // remove top, set head to underlying node
    Node* to_pop = _head;
    if (_size == 0) _head = nullptr;
    else _head = to_pop->GetNext();
    delete to_pop;

    _size--;
  };

  bool IsEmpty() {
    return _size == 0;
  };
  
  bool IsFull() {
    return _size == _capacity;
  };

  Node* GetTop() {
    return _head;
  };
};


int main() {
  std::cout << "Testing Dynamic Array Stack..." << std::endl;
  Stack s;

  s.Push(10);
  s.Push(20);
  s.Push(30);
  s.Push(40);

  while (!s.IsEmpty()) {
    std::cout << s.Peek() << std::endl;
    s.Pop();
  }


  std::cout << "Testing Linked List Stack..." << std::endl;
  LLStack lls;
  lls.Push(10);
  lls.Push(20);
  lls.Push(30);
  lls.Push(40);

  while (!lls.IsEmpty()) {
    std::cout << lls.GetTop()->GetData() << std::endl;
    lls.Pop();
  }
}
