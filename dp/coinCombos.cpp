#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int dpTest(int goal, vector<int> &coins) {
    vector<int> dp(goal + 1, 0);
    dp[0] = 1;

    for (int i = 0; i <= goal; ++i) {
      for (int coin : coins) {
        if ((i - coin) < 0)
          continue;

        dp[i] += dp[i - coin];
      }
      cout << "i: " << i << " | dp[i]: " << dp[i] << endl;
    }

    return dp[goal];
  }
};

int main() {
  Solution s;
  vector<int> coins;
  int goal;

  coins = {1, 4, 5};
  goal = 20;
  cout << "goal: " << goal << " coins: ";
  for (int &coin : coins)
    cout << coin << " ";
  cout << endl;
  cout << s.dpTest(goal, coins) << endl;
}
