#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int coinCombinations(int goal, vector<int> &coins) {
    vector<int> dp(goal + 1, 0);
    dp[0] = 1;

    for (int &coin : coins)
      for (int i = coin; i <= goal; ++i)
        dp[i] += dp[i - coin];

    return dp[goal];
  }
};

int main() {
  Solution s;
  vector<int> coins;
  int goal;

  coins = {1, 3, 7, 11, 13};
  goal = 500;

  cout << "Goal:   " << goal << "\nCoins:  ";
  for (int &coin : coins)
    cout << coin << " ";
  cout << endl;

  cout << "Combos: " << s.coinCombinations(goal, coins) << endl;
}
