#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int getCommon(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    int p1 = 0, p2 = 0;

    while (p1 < n1 && p2 < n2) {
      if (nums1[p1] == nums2[p2])
        return nums1[p1];
      else if (nums1[p1] < nums2[p2])
        ++p1;
      else
        ++p2;
    }

    return -1;
  }
};

int main() {
  Solution s;
  vector<int> nums1;
  vector<int> nums2;

  nums1 = {1, 2, 3};
  nums2 = {2, 4};
  cout << s.getCommon(nums1, nums2) << endl;

  nums1 = {1, 2, 3, 6};
  nums2 = {2, 3, 4, 5};
  cout << s.getCommon(nums1, nums2) << endl;

  nums1 = {0, 1, 2, 3, 4};
  nums2 = {5, 6, 7, 8, 9};
  cout << s.getCommon(nums1, nums2) << endl;

  nums1 = {1, 1, 2};
  nums2 = {2, 4};
  cout << s.getCommon(nums1, nums2) << endl;
}
