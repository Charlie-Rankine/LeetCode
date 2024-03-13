#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int pivotInteger(int R) {
    int L = 1, RTotal = 0, LTotal = 0;

    while (R - L)
      if (LTotal < RTotal)
        LTotal += L++;
      else
        RTotal += R--;

    return (LTotal == RTotal) ? L : -1;
  }
};

int main() {
  Solution s;

  cout << s.pivotInteger(8) << endl;
  cout << s.pivotInteger(1) << endl;
  cout << s.pivotInteger(4) << endl;
  cout << s.pivotInteger(288) << endl;
  cout << s.pivotInteger(1000) << endl;
}
