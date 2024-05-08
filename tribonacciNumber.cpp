#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int tribonacci(int n) {
    if (n < 2)
      return n;
    if (n == 2)
      return 1;

    int first = 0, second = 1, third = 1, fourth = 2;

    while (n-- > 3) {
      first = second;
      second = third;
      third = fourth;
      fourth = first + second + third;
    }

    return fourth;
  }
};

int main() {
  Solution s;

  for (int i = 0; i <= 25; ++i)
    cout << i << ": " << s.tribonacci(i) << endl;
}
