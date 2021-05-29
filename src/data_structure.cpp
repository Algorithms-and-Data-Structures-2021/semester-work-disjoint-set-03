#include "data_structure.hpp"

namespace itis {

  DisjointSet::DisjointSet(int n) : subset_count{n}, size{n} {
    for (int i = 0; i < n; i++) {
      elements.emplace_back(Element(i));
    }
  }

  void DisjointSet::make_set() {
    elements.emplace_back(Element(size));
    size++;
    subset_count++;
  }

  int DisjointSet::find(int node) {
    // Validate the argument
    if (node < 0 || node >= size) {
      throw std::invalid_argument("No such element");
    }

    // Recursively climb to the root of the tree, simultaneously suspending all the vertices encountered from the root.
    // This helps to find the representatives of these elements faster next time.
    // This method is called path compression.
    if (elements[node].parent != node) {
      elements[node].parent = find(elements[node].parent);
    }

    return elements[node].parent;
  }

  void DisjointSet::join(int x, int y) {
    // Find the representatives of the elements
    int root_x = find(x);
    int root_y = find(y);

    // If the elements are in the same subset, then you do not need to combine them
    if (root_x == root_y) {
      return;
    }

    // In order not to increase the height of the height, we hang the smaller tree from the larger one.
    // And if the heights of the trees are equal, then we suspend it to the first one and increase its rank.
    // The method is called Union By Rank.
    if (elements[root_x].rank < elements[root_y].rank) {
      elements[root_x].parent = root_y;
    } else if (elements[root_x].rank > elements[root_y].rank) {
      elements[root_y].parent = root_x;
    } else {
      elements[root_y].parent = root_x;
      elements[root_x].rank++;
    }

    // Successful union decreases the number of subsets by 1
    subset_count--;
  }

}  // namespace itis