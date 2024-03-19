#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
/*
* Solution 1:
*   Brute Force
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    unordered_map<int, vector<vector<int>>> pairs;

    for (int i = 0; i < nums.size(); ++i)
      for (int j = i + 1; j < nums.size(); ++j)
        pairs[nums[i] + nums[j]].push_back({i, j});

    for (int i = 0; i < nums.size(); ++i)
      for (vector<int> &v : pairs[0 - nums[i]])
        if (v[0] != i && v[1] != i) {
          vector<int> temp = {nums[i], nums[v[0]], nums[v[1]]};
          sort(temp.begin(), temp.end());
          ans.push_back(temp);
        }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    return ans;
  }
};
*
* Solution 2:
*   Two pointers
*/
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
      if (i && nums[i] == nums[i - 1])
        continue;

      int target = -nums[i], left = i + 1, right = nums.size() - 1, sum;

      while (left < right) {
        sum = nums[left] + nums[right];

        if (sum == target) {
          ans.push_back({nums[i], nums[left], nums[right]});

          while (left < right && nums[left] == nums[left + 1])
            ++left;
          while (left < right && nums[right] == nums[right - 1])
            --right;

          ++left;
          --right;
        } else if (sum < target) {
          ++left;
        } else {
          --right;
        }
      }
    }

    return ans;
  }
};

int main() {
  Solution s;
  vector<int> v;

  cout << "Test Case 1:" << endl;
}
