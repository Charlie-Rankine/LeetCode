#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  --n;

  long long start;
  cin >> start;

  long long prev = start, ans = 0, num, s;
  while (n--) {
    cin >> num;
    s = (prev - num >= 0) ? prev - num : 0;
    ans += s;
    prev = num + s;
  }

  cout << ans;
}
