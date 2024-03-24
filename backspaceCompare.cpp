#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool backspaceCompare(string s, string t) {
    stack<char> s_stack;
    stack<char> t_stack;

    for (char &c : s) {
      if (c == '#') {
        if (!s_stack.empty()) {
          s_stack.pop();
        }
      } else {
        s_stack.push(c);
      }
    }

    for (char &c : t) {
      if (c == '#') {
        if (!t_stack.empty()) {
          t_stack.pop();
        }
      } else {
        t_stack.push(c);
      }
    }

    if (s_stack.size() != t_stack.size())
      return false;

    while (!s_stack.empty()) {
      if (s_stack.top() != t_stack.top())
        return false;

      s_stack.pop();
      t_stack.pop();
    }

    return true;
  }
};

int main() {
  Solution s;
  string str1;
  string str2;

  str1 = "ab#c";
  str2 = "ad#c";
  cout << (s.backspaceCompare(str1, str2) ? "True" : "False") << endl;

  str1 = "ab##";
  str2 = "c#d#";
  cout << (s.backspaceCompare(str1, str2) ? "True" : "False") << endl;

  str1 = "a#c";
  str2 = "b";
  cout << (s.backspaceCompare(str1, str2) ? "True" : "False") << endl;

  str1 = "y#fo##f";
  str2 = "y#f#o##f";
  cout << (s.backspaceCompare(str1, str2) ? "True" : "False") << endl;

  str1 = "fbf##lkgnsb###fkgd##gfdgdfgnrdg#r###r#o##l";
  str2 = "fh#fjk#g#y#fr#fps#nfr#bgf#r#o##f#fu#gjgghd##";
  cout << (s.backspaceCompare(str1, str2) ? "True" : "False") << endl;
}
