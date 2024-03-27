#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    if (k <= 1)
      return 0;

    int total = 1, count = 0;

    for (int right = 0, left = 0; right < nums.size(); ++right) {
      total *= nums[right];

      while (total >= k) {
        total /= nums[left];
        left++;
      }

      count += right - left + 1;
    }

    return count;
  }
};

int main() {
  Solution s;
  vector<int> nums;

  nums = {10, 5, 2, 6};
  cout << s.numSubarrayProductLessThanK(nums, 100) << endl;
  nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  cout << s.numSubarrayProductLessThanK(nums, 47) << endl;
}
