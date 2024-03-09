#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    string ans;

    map<int, string> letters;
    letters[1000] = "M";
    letters[900] = "CM";
    letters[500] = "D";
    letters[400] = "CD";
    letters[100] = "C";
    letters[90] = "XC";
    letters[50] = "L";
    letters[40] = "XL";
    letters[10] = "X";
    letters[9] = "IX";
    letters[5] = "V";
    letters[4] = "IV";
    letters[1] = "I";

    for (auto iter = letters.rbegin(); iter != letters.rend(); ++iter) {
      while (num >= iter->first) {
        ans += iter->second;
        num -= iter->first;
      }
    }

    return ans;
  }
};

int main() {
  Solution s;

  cout << "3    = " << s.intToRoman(3) << endl;
  cout << "69   = " << s.intToRoman(69) << endl;
  cout << "135  = " << s.intToRoman(135) << endl;
  cout << "671  = " << s.intToRoman(671) << endl;
  cout << "1349 = " << s.intToRoman(1349) << endl;
  cout << "2067 = " << s.intToRoman(2067) << endl;
  cout << "3333 = " << s.intToRoman(3333) << endl;
  cout << "3999 = " << s.intToRoman(3999) << endl;
}
