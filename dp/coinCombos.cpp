#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dpTest(int goal, vector<int> coins) {
        int dp[goal+1] = { 0 };
        dp[0] = 1;

        for (int i = 0; i <= goal; ++i) {
            for (int coin : coins) {
                if ((i - coin) < 0)
                    continue;

                dp[i] += dp[i-coin];
            }
            cout << "i: " << i << " | dp[i]: " << dp[i] << endl;
        }
        
        return dp[goal];
    }
};

int main() {
    Solution s;
    cout << s.dpTest(20, { 1, 4, 5 }) << endl;
}

