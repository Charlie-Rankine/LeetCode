#include <iostream>

using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    int ans = 0;

    if (x < 0 || (x != 0 && x % 10 == 0))
      return false;

    while (x > ans) {
      ans = (ans * 10) + (x % 10);
      x /= 10;
    }

    return x == ans || x == ans / 10;
  }
};

int main() {
  Solution s;

  cout << (s.isPalindrome(121) ? "True" : "False") << endl;
  cout << (s.isPalindrome(100) ? "True" : "False") << endl;
  cout << (s.isPalindrome(573458734) ? "True" : "False") << endl;
  cout << (s.isPalindrome(1234554321) ? "True" : "False") << endl;
  cout << (s.isPalindrome(123454321) ? "True" : "False") << endl;
}
