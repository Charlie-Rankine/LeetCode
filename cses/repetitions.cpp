#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  int largest = 0, count = 0;
  char current = '!';

  cin >> s;
  for (char &c : s) {
    if (current == c) {
      ++count;
    } else {
      current = c;
      largest = max(largest, count);
      count = 1;
    }
  }

  largest = max(largest, count);
  cout << largest;
}
