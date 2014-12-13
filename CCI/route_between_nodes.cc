// Given a directed graph, determine if there exists a route between two nodes.

#include <iostream>
#include <vector>

struct GraphNode {
  std::vector<GraphNode*> children;
  int data;
  bool visited = false;
};

struct QueueNode {
  GraphNode* gn_ptr;
  QueueNode* next;
};

class Queue {
  int capacity = 1000;
  int size = 0;
  QueueNode* head; // first-in
  QueueNode* tail; // last-in

public:
  void PushFront(GraphNode* gn) {
    if (size == capacity) throw std::out_of_range("Queue overflow.");

    QueueNode qn;
    qn.gn_ptr = gn;

    // new node will be the new tail
    if (size == 0) head = &qn;
    else tail->next = &qn;
    tail = &qn;
    
    size++;
  };

  GraphNode* PopBack() {
    if (size == 0)  throw std::out_of_range("Empty queue can't be dequeued.");

    // remove old head and assign new head
    QueueNode* to_deq = head;
    if (size == 2) head = tail = to_deq;
    else if (size == 1) head = tail = nullptr;
    else head = to_deq->next;

    size--;
    return to_deq->gn_ptr;
  };

  bool IsEmpty() {return (size == 0);};
};


bool RouteExists(GraphNode* from, GraphNode* to) {
  std::cout << "Checking for route between " << from->data
	    << " and " << to->data << std::endl;
  Queue q;

  while (!q.IsEmpty()) {
    GraphNode* next = q.PopBack(); // returns popped node
    std::cout << next->data << " visited" << std::endl;
    if (next == to) return true;
    next->visited = true;
    for (int i=0; i<next->children.size(); i++) {
      GraphNode* c = next->children[i];
      if (c->visited != true) q.PushFront(c);
    }
  }
  return false;
}


int main() {
  // TEST 1 (True)
  GraphNode gn0;
  GraphNode gn1;
  GraphNode gn2;
  GraphNode gn3;
  
  gn0.data = 0;
  gn1.data = 1;
  gn2.data = 2;
  gn3.data = 3;

  gn0.children.push_back(&gn1);
  gn1.children.push_back(&gn2);
  gn2.children.push_back(&gn1);
  gn2.children.push_back(&gn3);
  gn3.children.push_back(&gn1);
  std::cout << (RouteExists(&gn0, &gn3)?"FALSE":"TRUE") << std::endl;


  // TEST 2 (False)
  GraphNode gn4;
  GraphNode gn5;
  GraphNode gn6;
  GraphNode gn7;
  
  gn4.data = 4;
  gn5.data = 5;
  gn6.data = 6;
  gn7.data = 7;

  gn4.children.push_back(&gn5);
  gn5.children.push_back(&gn6);
  gn6.children.push_back(&gn5);
  gn7.children.push_back(&gn5);
  std::cout << (RouteExists(&gn4, &gn7)?"FALSE":"TRUE") << std::endl;
}
