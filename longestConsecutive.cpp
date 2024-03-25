#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    int ans = 1, count = 1;

    if (!nums.size())
      return 0;

    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] != nums[i - 1]) {
        if (nums[i] == nums[i - 1] + 1)
          count++;
        else {
          if (ans < count)
            ans = count;

          count = 1;
        }
      }
    }

    return max(ans, count);
  }
};
