#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> ans(nums.size());
    int total = 1, zeros = 0;

    for (int num : nums)
      if (num != 0)
        total *= num;
      else
        ++zeros;

    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] == 0)
        ans[i] = (zeros > 1) ? 0 : total;
      else
        ans[i] = (zeros) ? 0 : total / nums[i];

    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums;

  cout << "Test Case 1:" << endl;
  nums = {1, 2, 3, 4};
  for (int i : s.productExceptSelf(nums))
    cout << i << " ";
  cout << endl;

  cout << "Test Case 2:" << endl;
  nums = {-10, -20, 22, 24, -1, 16, 3, -12, 28};
  for (int i : s.productExceptSelf(nums))
    cout << i << " ";
  cout << endl;

  cout << "Test Case 3:" << endl;
  nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (int i : s.productExceptSelf(nums))
    cout << i << " ";
  cout << endl;

  cout << "Test Case 4:" << endl;
  for (int i : s.productExceptSelf(nums))
    cout << i << " ";
  cout << endl;
}
