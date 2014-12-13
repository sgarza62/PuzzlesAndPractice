#include <iostream>

class Node {
  int data;
  Node* next;

public:
  Node() {};
  void setData(int d) {data = d;};
  void setNext(Node* n) {next = n;};
  int getData() {return data;};
  Node* getNext() {return next;};
};


class LinkedList {
  Node* head;

public:
  LinkedList() {head = nullptr;};

  void append(int d) {
    // Create a new node
    Node* newNode = new Node();
    newNode->setData(d);
    newNode->setNext(NULL);

    // Create a temp pointer
    Node *tmp = head;

    if ( tmp != NULL ) {
      // Nodes already present in the list
      // Parse to end of list
      while ( tmp->getNext() != NULL ) {
        tmp = tmp->getNext();
      }

      // Point the last node to the new node
      tmp->setNext(newNode);
    }
    else {
      // First node in the list
      head = newNode;
    }
  };
  

  void Print() {
    Node* tmp = head;
    while (tmp != nullptr) {
      std::cout << tmp->getData() << std::endl;
      tmp = tmp->getNext();
    }
  };

};


int main() {
  LinkedList l;
  l.append(10);
  l.append(20);
  l.append(30);
  l.Print();
}
