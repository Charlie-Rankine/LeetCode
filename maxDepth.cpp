#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int maxDepth(string s) {
    int count = 0, max_depth = 0;

    for (char &c : s) {
      if (c == '(') {
        ++count;
        continue;
      }
      if (c == ')') {
        max_depth = max(max_depth, count);
        --count;
      }
    }

    return max_depth;
  }
};

int main() {
  Solution s;
  vector<string> test_cases{"(1+(2*3)+((8)/4))+1", "(1)+((2))+(((3)))",
                            "(1+(((2*3)))+((8)/4))+1"};

  for (string &str : test_cases)
    cout << str << ": " << s.maxDepth(str) << endl;
}
