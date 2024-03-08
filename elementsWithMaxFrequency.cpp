#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int maxFrequencyElements(vector<int> &numbers) {
    unordered_map<int, int> counts;
    int largest = 0;
    int count = 0;

    for (int num : numbers) {
      if (++counts[num] > largest) {
        largest = counts[num];
        count = 1;
      } else if (counts[num] == largest)
        ++count;
    }

    return count * largest;
  }
};

int main() {
  Solution s;
  vector<int> nums;

  nums = {81, 81, 81, 81, 81, 81, 81, 17, 28, 81, 81, 56, 81, 54, 81, 81,  81,
          81, 81, 60, 81, 28, 81, 81, 81, 81, 81, 54, 81, 81, 81, 81, 100, 28};
  cout << s.maxFrequencyElements(nums) << endl;

  nums = {1, 2, 3, 4, 5};
  cout << s.maxFrequencyElements(nums) << endl;
  nums = {1, 2, 2, 3, 1, 4};
  cout << s.maxFrequencyElements(nums) << endl;
}
