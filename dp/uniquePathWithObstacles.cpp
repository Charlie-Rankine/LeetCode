class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (obstacleGrid[0][0])
      return 0; 
      
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0]= 1;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!(i+j) || obstacleGrid[i][j])
          continue;

        if (!j)
          dp[i][j] = dp[i-1][j];
        else if (!i)
          dp[i][j] = dp[i][j-1];
        else
          dp[i][j] = dp[i][j-1] + dp[i-1][j];
      }
    }

    return dp.back().back();
  }
};
