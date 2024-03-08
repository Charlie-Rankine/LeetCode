#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    int count = 0, i = s.size() - 1;
    if (s.size() == 1)
      return 1;

    while (!isalpha(s[i]))
      --i;

    while (~i && isalpha(s[i])) {
      ++count;
      --i;
    }

    return count;
  }
};

int main() {
  Solution s;

  cout << s.lengthOfLastWord("Hello World") << endl;
  cout << s.lengthOfLastWord("   fly me    to    the moon   ") << endl;
  cout << s.lengthOfLastWord("luffy is a still joyboy") << endl;
  cout << s.lengthOfLastWord("a") << endl;
  cout << s.lengthOfLastWord(" a") << endl;
}
