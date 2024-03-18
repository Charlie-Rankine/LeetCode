#include <iostream>

using namespace std;

int main() {
  int n, num, total = 1;
  cin >> n;

  while (--n) {
    cin >> num;
    total += (n + 1) - num;
  }

  cout << total;
}
