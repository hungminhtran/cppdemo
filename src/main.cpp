#include <iostream>
#include <vector>

#include <queue>
using namespace std;

class Solution {
public:
  int jump(vector<int> &nums) {
    if (nums.size() == 1) {
      return 0;
    }
    queue<int> bfs_queue = {};

    vector<int> tracing(nums.size(), -1);
    bfs_queue.push(0);
    tracing[0] = -1;

    while (!bfs_queue.empty()) {
      int current_index = bfs_queue.front();
      bfs_queue.pop();

      int end_index = (int)nums.size() - 1;
      if (current_index < end_index &&
          nums.at(current_index) + current_index < end_index) {
        end_index = nums.at(current_index) + current_index;
      } else {
        tracing[end_index] = current_index;
        break;
      }

      for (int next_index = current_index + 1; next_index <= end_index;
           next_index++) {
        if (tracing[next_index] >= 0) {
          continue;
        }
        bfs_queue.push(next_index);
        tracing[next_index] = current_index;
      }
    }

    int min_jump = 0;
    int index = (int)nums.size() - 1;
    do {

      if (index >= 0) {
        index = tracing[index];

        min_jump++;
      } else {
        break;
      }
    } while (index != 0);


    return min_jump;
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
  vector<vector<int>> numx = {{2, 3, 1, 1, 4},
                              {3, 2, 1, 0, 4},
                              {0, 0, 0, 0, 0},
                              {1},
                              {0},
                              {9},
                              {0, 1},
                              {1, 0},
                              {9, 1, 0},
                              {9, 0, 0, 0},
                              {0, 1, 2},
                              {1, 2},
                              {1, 1, 1, 1, 1},
                              {1, 2, 3, 4, 5},
                              {5, 4, 3, 2, 1},
                              {2, 1, 1, 1, 1}};
  for (auto nums : numx) {
    cout << solution.jump(nums) << "____";
    print_vector(nums);
  }

  cout << "****** end *****" << endl;
  return 0;
}