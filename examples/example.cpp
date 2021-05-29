#include <iostream>
#include "data_structure.hpp"

using namespace std;
using namespace itis;

int main(int argc, char **argv) {
  int n, m;
  int num1, num2;
  cin >> n >> m;


  DisjointSet* d_set = new DisjointSet(n);

  for (int i = 0; i < m; i++) {
    cin >> num1 >> num2;

    // Combine 2 subsets (connectivity components) into one subset (connectivity component)
    // Each successful union decreases the number of subsets (connectivity components) by 1
    d_set->join(num1-1, num2-1);
  }
  cout << "Number of connectivity components: " << d_set->subset_count << endl;
  return 0;
}