#include "TreeNode.cpp"
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    int total = 0;

    unordered_map<char, int> numerals;
    numerals['I'] = 1;
    numerals['V'] = 5;
    numerals['X'] = 10;
    numerals['L'] = 50;
    numerals['C'] = 100;
    numerals['D'] = 500;
    numerals['M'] = 1000;

    for (int i = 0; i < s.size(); ++i) {
      if (i + 1 < s.size() && numerals[s[i + 1]] > numerals[s[i]])
        total -= numerals[s[i]];
      else
        total += numerals[s[i]];
    }

    return total;
  }
};

int main() {
  Solution s;
  vector<int> nums;

  cout << s.romanToInt("III") << endl;
  cout << s.romanToInt("LVIII") << endl;
  cout << s.romanToInt("MCMXCIV") << endl;
}
