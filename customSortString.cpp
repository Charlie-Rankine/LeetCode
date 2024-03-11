#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string customSortString(string o, string s) {
    string ans;

    for (char &letter : o) {
      size_t foundLetter = s.find(letter);

      while (foundLetter != s.npos) {
        ans.push_back(letter);
        s.erase(foundLetter, 1);
        foundLetter = s.find(letter);
      }
    }

    return ans + s;
  }
};

int main() {
  Solution s;

  cout << "Test case 1:" << endl;
  cout << s.customSortString("cba", "abcd") << endl;

  cout << "Test case 2:" << endl;
  cout << s.customSortString("bcafg", "abcd") << endl;

  cout << "Test case 3:" << endl;
  cout << s.customSortString("mwnebrvtlaphdu", "mcldhriupaqg") << endl;

  cout << "Test case 4: Every Letter of the alphabet" << endl;
  cout << s.customSortString("abcdefghijklmnopqrstuvwxyz",
                             "zyxwvutsrqponmlkjihgfedcba")
       << endl;

  cout << "Test case 5: Every Letter of the alphabet twice" << endl;
  cout << s.customSortString(
              "abcdefghijklmnopqrstuvwxyz",
              "zzyyxxwwvvuuttssrrqqppoonnmmllkkjjiihhggffeeddccbbaa")
       << endl;

  cout << "Test case 6: Single different character" << endl;
  cout << s.customSortString("a", "z") << endl;

  cout << "Test case 7: Single same character" << endl;
  cout << s.customSortString("a", "a") << endl;

  cout << "Test case 8: Bunch of repeats (blimpy)" << endl;
  cout << s.customSortString("blimpy",
                             "blimpyblimpyblimpyblimpyblimpyblimpyblimpy")
       << endl;
}
