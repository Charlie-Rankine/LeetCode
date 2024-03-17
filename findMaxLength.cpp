#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
 * Two solutions, both not too different in efficiency
 */
class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    int n = nums.size(), sum = 0, ans = 0;
    vector<int> runningSum(n);
    map<int, vector<int>> m;
    m[0].push_back(-1);

    for (int i = 0; i < n; ++i) {
      if (nums[i])
        runningSum[i] = ++sum;
      else
        runningSum[i] = --sum;

      m[sum].push_back(i);
    }

    for (auto [sum, v] : m)
      ans = max(ans, v.back() - v.front());

    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums;

  cout << "Test case 1: " << endl;
  nums = {1, 1, 0, 0, 1, 1, 0, 1, 1};
  cout << s.findMaxLength(nums) << endl;

  cout << "Test case 2: " << endl;
  nums = {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0};
  cout << s.findMaxLength(nums) << endl;

  cout << "Test case 3: " << endl;
  nums = {0, 1};
  cout << s.findMaxLength(nums) << endl;
}

/*
* class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      for(auto &i: nums)
        if(!i)
          i = -1;

      int ans = 0, sum = 0;
      unordered_map<int,int> mp;

      for(int i = 0; i < nums.size(); ++i){
        sum += nums[i];

        if(!sum)
          ans = i + 1;

        if(mp.count(sum))
          ans = max(ans, i - mp[sum]);

        if(!mp.count(sum))
          mp[sum] = i;
      }

    return ans;
  }
};
*
*/
