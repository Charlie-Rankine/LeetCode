#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &p) {
    sort(p.begin(), p.end());

    int lastPopped = p[0][1];
    int ans = 1;

    for (auto &point : p) {
      // Check if the current balloon's start (point[0]) is is beyond the
      // endpoint of the previous burst balloon
      if (point[0] > lastPopped) {
        ans++;
        lastPopped = point[1];
      }

      lastPopped = min(point[1], lastPopped);
    }

    return ans;
  }
};

int main() {
  Solution s;
  vector<vector<int>> points;
  int required;

  cout << "Test case 1:" << endl;
  //       {{1, 6}, {2, 8}, {7, 12}, {10, 16}};
  points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  required = s.findMinArrowShots(points);
  cout << "Arrows required: " << required << "\n" << endl;

  cout << "Test case 2:" << endl;
  points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  required = s.findMinArrowShots(points);
  cout << "Arrows required: " << required << "\n" << endl;

  cout << "Test case 3:" << endl;
  points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
  required = s.findMinArrowShots(points);
  cout << "Arrows required: " << required << "\n" << endl;

  cout << "Test case 4:" << endl;
  points = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5},
            {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 10}};
  required = s.findMinArrowShots(points);
  cout << "Arrows required: " << required << "\n" << endl;
}
