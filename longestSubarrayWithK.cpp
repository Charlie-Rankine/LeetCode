#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubarrayLength(vector<int> &nums, int k) {
    unordered_map<int, int> counts;
    int largest = 0, length = 0, maxFrequency = 0;

    for (int left = 0, right = 0; right < nums.size(); ++right) {
      ++counts[nums[right]];

      if (counts[nums[right]] > k) {
        while (nums[left] != nums[right])
          --counts[nums[left++]];

        --counts[nums[left]];
        ++left;
      }

      largest = max(largest, right - left + 1);
    }

    return largest;
  }
};

int main() {
  Solution s;
  vector<int> nums;

  nums = {1, 2, 3, 1, 2, 3, 1, 2};
  cout << s.maxSubarrayLength(nums, 2) << endl;

  nums = {1, 2, 1, 2, 1, 2, 1, 2};
  cout << s.maxSubarrayLength(nums, 1) << endl;

  nums = {5, 5, 5, 5, 5, 5, 5};
  cout << s.maxSubarrayLength(nums, 4) << endl;
}
