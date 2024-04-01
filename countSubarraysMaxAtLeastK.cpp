#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  long long countSubarrays(vector<int> &nums, int k) {
    int n = nums.size(), left = 0, right = 0, ans = 0, maxElements = 0;
    int maximum = *max_element(nums.begin(), nums.end());

    while (right < n) {
      if (nums[right] == maximum)
        ++maxElements;

      if (maxElements >= k) {
        while (maxElements >= k) {
          ans += n - right;
          if (nums[left] == maximum)
            --maxElements;
          ++left;
        }
      }

      ++right;
    }

    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums;

  nums = {1, 3, 2, 3, 3};
  cout << s.countSubarrays(nums, 2) << endl;

  nums = {1, 4, 2, 1};
  cout << s.countSubarrays(nums, 3) << endl;
}
