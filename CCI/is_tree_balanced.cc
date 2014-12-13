// Write a function to check if a tree is balanced (ie, heights of subtrees of a
// node never differ by more than 1).

#include <iostream>

struct Node {
  Node* left = nullptr;
  Node* right = nullptr;
  int data;
};

struct Tree {
  Node* root = nullptr;
};


bool PreOrder(Node* n, int& curr, int& max) {
  // check if leaf...
  if ((n->left == nullptr) && (n->right == nullptr)) {
    if (max == 0 || curr == max+1) max = curr;
    else if (!(curr == max || curr == max-1)) return false;
  } else {
    // increase height
    curr++;

    // preorder left
    if (n->left != nullptr) {
      if (PreOrder(n->left, curr, max) == false) {
	return false;
      }
    }

    // preorder right
    if (n->right != nullptr) {
      if (PreOrder(n->right, curr, max) == false) {
	return false;
      }
    }

    // decrease height
    curr--;
  }
  return true;
}


bool IsBalanced(Tree* t) {
  int max = 0;
  int curr = 0;
  return PreOrder(t->root, max, curr);
}






int main() {
  Tree t;

  Node n;
  n.data = 1;
  t.root = &n;

  Node l;
  l.data = n.data+1;
  n.left = &l;

  Node r;
  r.data = n.data+2;
  n.right = &r;

  Node ll;
  ll.data = l.data+2;
  l.left = &ll;

  Node lr;
  lr.data = l.data+3;
  l.right = &lr;

  Node rl;
  rl.data = r.data+3;
  r.left = &rl;

  Node rr;
  rr.data = r.data+4;
  r.right = &rr;

  Node extra;
  extra.data = 9;
  rl.left = &extra;

  std::cout << IsBalanced(&t) << std::endl;

  // add this to make tree unbalanced...
  Node xxtra; //  >:)
  xxtra.data = 0;
  extra.left = &xxtra;

  std::cout << IsBalanced(&t) << std::endl;
}
