#include <iostream>

using namespace std;

class Solution {
public:
  int dpTest(int columns, int rows) {
    int dp[columns][rows];

    for (int y = 0; y < rows; ++y)
      for (int x = 0; x < columns; ++x) {
        if (x - 1 < 0 || y - 1 < 0)
          dp[x][y] = 1;
        else
          dp[x][y] = dp[x - 1][y] + dp[x][y - 1];
      }

    for (int y = 0; y < rows; ++y) {
      for (int x = 0; x < columns; ++x)
        cout << dp[x][y] << " ";
      cout << endl;
    }

    return dp[columns - 1][rows - 1];
  }
};

int main() {
  Solution s;

  int cin1, cin2;
  cout << "Enter x, y seperated by a space: ";
  cin >> cin1 >> cin2;

  int result = s.dpTest(cin1, cin2);
  cout << "Result: " << result << endl;
}
