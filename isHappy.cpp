#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  bool isHappy(int n) {
    set<int> s;

    while (s.insert(n).second) {
      int temp = 0;

      while (n) {
        temp += (n % 10) * (n % 10);
        n /= 10;
      }

      n = temp;

      if (n == 1)
        return true;
    }

    return false;
  }
};

int main() {
  Solution s;
  vector<int> nums = {7, 9, 601, 888, 1'247, 6'969, 41'705, 69'696};

  for (int &num : nums)
    cout << num << ": " << (s.isHappy(num) ? "True" : "False") << endl;
}
