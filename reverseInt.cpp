#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
  int reverseInt(int x) {
    int ans = 0;

    while (x) {
      if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
        return 0;

      ans = (ans * 10) + (x % 10);
      x /= 10;
    }

    return ans;
  }
};

int main() {
  Solution s;

  cout << s.reverseInt(123) << endl;
  cout << s.reverseInt(34758) << endl;
  cout << s.reverseInt(-5659) << endl;
  cout << s.reverseInt(-2'147'000'009) << endl;
  cout << s.reverseInt(2'147'000'009) << endl;
}
