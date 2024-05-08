#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string reversePrefix(string word, char ch) {
    for (auto ptr = word.begin(); ptr != word.end(); ++ptr)
      if (*ptr == ch) {
        reverse(word.begin(), ++ptr);
        break;
      }

    return word;
  }
};

int main() {
  Solution s;

  cout << s.reversePrefix("abcdefd", 'd') << endl;
  cout << s.reversePrefix("xyxzxe", 'z') << endl;
  cout << s.reversePrefix("abcd", 'z') << endl;
}
