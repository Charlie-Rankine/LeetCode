#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
/*
 * This question is terrible.
 * "Find the intersection" should instead be "Find all numbers shared"
 */
class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> s1(nums1.begin(), nums1.end());
    unordered_set<int> s2(nums2.begin(), nums2.end());
    vector<int> ans;

    for (const int &num : s1)
      if (s2.find(num) != s2.end())
        ans.push_back(num);

    return ans;
  }
};

int main() {
  Solution s;
  vector<int> v1;
  vector<int> v2;

  cout << "Test case 1:" << endl;
  v1 = {1, 2, 2, 1};
  v2 = {2, 2};
  for (int &num : s.intersection(v1, v2))
    cout << num << " ";
  cout << endl;

  cout << "Test case 2:" << endl;
  v1 = {4, 9, 5};
  v2 = {9, 4, 9, 8, 4};
  for (int &num : s.intersection(v1, v2))
    cout << num << " ";
  cout << endl;

  cout << "Test case 3:" << endl;
  v1 = {1, 2, 3, 4, 5};
  v2 = {0, 1, 2, 7, 7};
  for (int &num : s.intersection(v1, v2))
    cout << num << " ";
  cout << endl;
}
