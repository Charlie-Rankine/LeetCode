#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <sstream>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(); 
    int n = matrix[0].size();
    int maxSize = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (!i || !j || !(matrix[i][j] - '0'))
          dp[i][j] = matrix[i][j] - '0';
        else
          dp[i][j] = min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + 1;
        
        maxSize = max(maxSize, dp[i][j]);
      }

    for (vector<int> v : dp) {
      for (int i : v) 
        cout << i << " "; 
      cout << endl;
    }

    return maxSize * maxSize;
  }
};

int main() {
  Solution s;
  vector<vector<char>> matrix;

  cout << "Test Case 1: " << endl;
  matrix = { {'1','0','1','0','0'}, {'1','0','1','1','1'}, {'1','1','1','1','1'}, {'1','0','0','1','0'} };
  cout << s.maximalSquare(matrix) << endl;

  cout << "Test Case 2: " << endl;
  matrix = { {'1','0','1','1','1'}, {'1','0','1','1','1'}, {'1','1','1','1','1'}, {'1','0','0','1','0'} };
  cout << s.maximalSquare(matrix) << endl;

  cout << "Test Case 3: " << endl;
  matrix = { {'0','1','1','1','1'}, {'0','1','1','1','1'}, {'0','1','1','1','1'}, {'0','1','1','1','1'} };
  cout << s.maximalSquare(matrix) << endl;

  cout << "Test Case 4: " << endl;
  matrix = { {'0','0','0','0','0','0' }, {'0','1','1','1','1','0'}, {'0','1','1','1','1','0'}, {'0','1','1','1','1','0'}, {'0','1','1','1','1','0'}, {'0','0','0','0','0','0' } };
  cout << s.maximalSquare(matrix) << endl;
}