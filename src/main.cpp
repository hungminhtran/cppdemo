#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  const int MAX_DUPLICATION = 1;

public:
  int removeDuplicates(vector<int> &nums) {

    if (nums.size() == 0) {
      return 0;
    }
    vector<int> result = {nums.at(0)};
    int count = 0;
    ulong index = 1;
    while (index < nums.size()) {
      int num_e = nums.at(index);

      if (num_e != result.at(result.size() - 1)) {
        count = 0;
        index++;
        result.push_back(num_e);
      } else if (count < MAX_DUPLICATION) {
        count++;
        index++;
        result.push_back(num_e);
      } else {
        count = 0;
        while (index < nums.size() && num_e == nums.at(index)) {
          index++;
        }
      }
    }
    nums.swap(result);
    return (int)nums.size();
  }
};

int main() {
  Solution solution;
  cout << "***** hello ******" << endl;
  vector<vector<int>> nums = {
      {1, 1, 1, 2, 2, 3},
      {0, 0, 1, 1, 1, 1, 2, 3, 3},
      {1, 2, 3, 4, 5},
      {1, 1, 2, 2, 3, 3, 4, 4, 5, 5},
      {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5},
      {},
      {1},
      {1, 1},
      {1, 1, 1},
      {1, 2},
      {1, 1, 2},
      {1, 1, 1, 2},
      {1, 1, 1, 2, 2},
      {1, 1, 1, 2, 2, 2},
      {1, 2, 2},
      {1, 2, 2, 2},
      {1, 1, 2, 2, 2},
      {1, 2, 3},
      {1, 1, 2, 3},
      {1, 1, 1, 2, 3},
      {1, 1, 1, 2, 2, 3},
      {1, 1, 1, 2, 2, 2, 3},
      {1, 1, 1, 2, 2, 2, 3, 3},
      {1, 1, 1, 2, 2, 2, 3, 3, 3},
  };
  for (vector<int> numx : nums) {
    cout << solution.removeDuplicates(numx);
    for (int a : numx)
      cout << " " << a;
    cout << "****** end *****" << endl;
  }
  return 0;
}