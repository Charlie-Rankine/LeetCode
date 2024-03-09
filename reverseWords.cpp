#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    string ans, word;

    for (int i = s.size() - 1; i >= 0; --i) {
      if (isalpha(s[i]) || isdigit(s[i])) {
        word += s[i];
      } else if (!word.empty() && s[i] == ' ') {
        reverse(word.begin(), word.end());
        ans += word;
        ans.push_back(' ');
        word.clear();
      }
    }

    if (!word.empty()) {
      reverse(word.begin(), word.end());
      ans += word;
      ans.push_back(' ');
    }

    ans.pop_back();
    return ans;
  }
};

int main() {
  Solution s;

  cout << s.reverseWords("the sky is blue") << endl;
  cout << s.reverseWords("   hello world") << endl;
  cout << s.reverseWords("a good    example") << endl;
}
