#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    for (int L = 0, R = s.size() - 1; R - L >= 1; ++L, --R) {
      while (L != R && !isalnum(s[L]))
        ++L;
      while (L != R && !isalnum(s[R]))
        --R;

      if (tolower(s[L]) != tolower(s[R]))
        return false;
    }

    return true;
  }
};

int main() {
  Solution s;

  cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
  cout << s.isPalindrome("race a car") << endl;
  cout << s.isPalindrome("racecar") << endl;
  cout << s.isPalindrome(" ") << endl;
}
