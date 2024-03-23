#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> opens;

    for (char &c : s) {
      if (c == '(' || c == '[' || c == '{')
        opens.push(c);
      else if (!opens.empty() && (c == opens.top() + 1 || c == opens.top() + 2))
        opens.pop();
      else
        return false;
    }

    return opens.empty();
  }
};

int main() {
  Solution s;

  for (string brackets : {"()", "()[]{}", "(]", "(())[([[]])]", "({{{{}}}))"})
    cout << (s.isValid(brackets) ? "True" : "False") << endl;
}
