#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int bagOfTokensScore(vector<int> &tokens, int power) {

    sort(tokens.begin(), tokens.end());

    int score = 0;
    while (!tokens.empty()) {
      if (power - tokens.front() >= 0) {
        power -= tokens.front();
        tokens.erase(tokens.begin());
        ++score;
        continue;
      }

      if (tokens.size() > 1 && tokens.back() > tokens.front() && score >= 1) {
        power += tokens.back();
        tokens.erase(tokens.end() - 1);
        --score;
        continue;
      }

      break;
    }

    return score;
  }
};

int main() {
  Solution s;
  vector<int> tokens;

  cout << "Test Case 1:" << endl;
  tokens = {100};
  cout << s.bagOfTokensScore(tokens, 50) << endl;

  cout << "Test Case 2:" << endl;
  tokens = {200, 100};
  cout << s.bagOfTokensScore(tokens, 150) << endl;

  cout << "Test Case 3:" << endl;
  tokens = {100, 200, 300, 400};
  cout << s.bagOfTokensScore(tokens, 200) << endl;
}
