#include <iostream>

using namespace std;

int main() {
  int c;
  cin >> c;

  if (c > 1 && c <= 3) {
    cout << "NO SOLUTION";
    return 0;
  }

  for (int i = 2; i; --i) {
    int n = i;

    while (n <= c) {
      cout << n << " ";

      n += 2;
    }
  }
}
