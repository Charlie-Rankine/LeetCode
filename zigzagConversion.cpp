#include <iostream>
#include <string>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
  string ans;
  vector<string> spiral(numRows);
  bool down = true;
  int pos = 0;

  if (numRows == 1)
    return s;

  for (int i = 0; i < s.size(); ++i) {
    spiral[pos] += s[i];

    if (down)
      ++pos;
    else
      --pos;

    if (!pos || pos == numRows - 1)
      down = !down;
  }

  for (string &letter : spiral)
    ans += letter;

  return ans;
}

int main() {
  cout << convert("PAYPALISHIRING", 3) << endl;
  cout << convert("PAYPALISHIRING", 4) << endl;
  cout << convert("Blimpy", 3) << endl;
  cout << convert("A", 1) << endl;
  cout << convert("A", 10) << endl;
  cout << convert("AB", 1) << endl;
  cout << convert("ABC", 2) << endl;
  cout << convert("whyareyoulookingatmygithub?", 5) << endl;
}
