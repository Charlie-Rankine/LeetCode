#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string makeGood(string s) {
    if (!s.size())
      return s;

    for (int i = 1; i < s.size(); ++i)
      while (abs(s[i - 1] - s[i]) == 32) {
        s.erase(s.begin() + i - 1, s.begin() + i + 1);
        if (i > 1)
          --i;
      }

    return s;
  }
};

int main() {
  Solution s;
  vector<string> test_cases = {"leEeetcode", "abBAcC", "s"};

  for (string &str : test_cases)
    cout << str << ": " << s.makeGood(str) << endl;
}
