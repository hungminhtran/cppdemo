#include <iostream>
#include <vector>

#include <queue>
using namespace std;

class Solution {
public:
  int hIndex(vector<int> &citations) {
    const int MAX_CITAIONS = citations.size();
    int h_index = 0;
    for (int citation_check = 1; citation_check <= MAX_CITAIONS;
         citation_check++) {
      int num_valid_paper = 0;
      for (int i = 0; i < MAX_CITAIONS; i++) {
        if (citations.at(i) >= citation_check) {
          num_valid_paper++;
        }
      }
      if (num_valid_paper >= citation_check) {
        h_index = citation_check;
      }
    }
    return h_index;
  }
};

template <typename T> void print_vector(vector<T> v) {
  for (auto e : v) {
    cout << e << " ";
  }
  cout << endl;
}

int main() {
  Solution solution;
  cout << "***** hello ******" << endl;
  vector<vector<int>> numx = {
      {3, 0, 6, 1, 5}, {1, 3, 1}, {3},    {0},    {1},    {2},
      {1, 2},          {1, 1},    {9, 9}, {0, 0}, {0, 1}, {0, 10}};
  for (auto nums : numx) {
    cout << solution.hIndex(nums) << "____";
    print_vector(nums);
  }

  cout << "****** end *****" << endl;
  return 0;
}