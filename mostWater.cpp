#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int highest = 0, shorter = 2e9;

    while (left != right) {
      shorter = min(height[left], height[right]);
      highest = max(highest, shorter * (right - left));

      if (height[left] <= height[right])
        ++left;
      else
        --right;
    }

    return highest;
  }
};

int main() {
  Solution s;
  vector<int> nums;

  nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << s.maxArea(nums) << endl;
}
