#include <vector>
#include <iostream>

using namespace std;

struct Edge {
  int source;
  int dest;
  int weight;
};

vector<int> topological_sort(const vector<int> &vertices, const vector<Edge> &edges) {
  // count in edges where indices correspond to vertices
  vector<int> in_degree(5, 0);
  for (int e=0; e<edges.size(); e++) {
    in_degree[edges[e].dest] += 1;
  }

  // list vertices that have no in edges, any of which are appropriate nodes to
  // visit next
  vector<int> next;
  for (int v=0; v<vertices.size(); v++) {
    if (in_degree[v] == 0) next.push_back(v);
  }

  // produce some list such that if there exists some edge (A, B), A comes
  // before B in the list
  vector<int> linear_order;
  while (next.size()) {
    // any element from next suffices
    int vertex_visiting = next.back();
    linear_order.push_back(vertex_visiting);
    next.pop_back();

    // by visiting some vertex A, any vertex that depends on A no longer has
    // that dependency, so we decrement any destination nodes' in_degree by one
    for (int e=0; e<edges.size(); e++) {
      if (edges[e].source == vertex_visiting) {
	int dependent_node = edges[e].dest;
	in_degree[dependent_node] -= 1;
	if (in_degree[dependent_node] == 0) {
	  next.push_back(dependent_node);
	}
      }
    }
  }

  return linear_order;
}

int main() {
  vector<int> vertices {0, 1, 2, 3, 4};

  vector<Edge> edges;
  edges.push_back(Edge {0, 1});
  edges.push_back(Edge {1, 2});
  edges.push_back(Edge {2, 4});
  edges.push_back(Edge {3, 4});

  vector<int> linear_order = topological_sort(vertices, edges);
  for (int i=0; i<linear_order.size(); i++) cout << linear_order[i] << ", ";
  cout << endl;
}
