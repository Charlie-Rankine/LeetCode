#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * CAN BE IMPROVED, CAN BE DONE BY BINARY SEARCHING TWICE
 */
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    if (!nums.size())
      return {-1, -1};

    // Implement binary search
    int left = 0, right = nums.size() - 1, middle;

    while (left <= right) {
      // Set middle
      middle = left + (right - left) / 2;

      // Check if target is middle
      if (nums[middle] == target)
        break;

      // If target is greater, move right
      if (nums[middle] < target)
        left = middle + 1;

      // If target is less, move left
      else
        right = middle - 1;
    }

    // Number is found, check for first and last
    if (nums[middle] != target)
      return {-1, -1};

    left = middle;
    right = middle;

    while (~(left - 1) && nums[left - 1] == nums[middle])
      --left;
    while (right + 1 < nums.size() && nums[right + 1] == nums[middle])
      ++right;

    return {left, right};
  }
};

int main() {
  Solution s;
  vector<int> nums;
  vector<int> ans;

  nums = {5, 7, 7, 8, 8, 10};
  ans = s.searchRange(nums, 8);
  cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

  nums = {5, 7, 7, 8, 8, 10};
  ans = s.searchRange(nums, 6);
  cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

  nums = {};
  ans = s.searchRange(nums, 0);
  cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

  nums = {1, 2, 3, 4, 5, 5, 5, 5};
  ans = s.searchRange(nums, 5);
  cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

  nums = {1, 1, 1, 1, 2, 3, 4, 5};
  ans = s.searchRange(nums, 1);
  cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

  nums = {0, 1};
  ans = s.searchRange(nums, 1);
  cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

  nums = {1, 0};
  ans = s.searchRange(nums, 1);
  cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;
}
