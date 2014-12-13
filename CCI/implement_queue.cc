#include <iostream>
#include <stdexcept>

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


class Queue {
  int _capacity = 100;
  int _size = 0;
  Node* _head; // first in
  Node* _tail; // latest in

public:
  void Enqueue(int d) {
    if (IsFull()) throw std::out_of_range ("Queue overflow.");

    // node will be the new tail
    Node* n = new Node;
    n->SetData(d);
    n->SetNext(nullptr);
    if (_size == 0) _head = n;
    else _tail->SetNext(n);
    _tail = n;

    _size++;
  };
  
  void Dequeue() {
    if (IsEmpty()) throw std::out_of_range ("Empty queue can't be dequeued.");

    // remove old head and reassign new head
    Node* to_dequeue = _head;
    if (_size == 2) _head = _tail = to_dequeue->GetNext();
    else if (_size == 1) _head = _tail = nullptr;
    else _head = to_dequeue->GetNext();
    delete to_dequeue;

    _size--;
  };

  bool IsEmpty() {
    return _size == 0;
  };

  bool IsFull() {
    return _size == _capacity;
  };

  Node* GetNext() {
    return _head;
  };
};

int main() {
  Queue q;
  q.Enqueue(10);
  q.Enqueue(20);
  q.Enqueue(30);
  q.Enqueue(40);

  while (!q.IsEmpty()) {
    std::cout << q.GetNext()->GetData() << std::endl;
    q.Dequeue();
  }
}
