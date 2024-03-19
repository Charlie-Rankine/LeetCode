#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    array<int, 26> freq{};
    int ans = 0, totalTasks = tasks.size();

    for (char &task : tasks)
      ++freq[task - 'A'];

    sort(freq.rbegin(), freq.rend());

    while (totalTasks) {
      int cooling = n + 1;

      for (int &count : freq) {
        if (!count)
          continue;

        if (!cooling)
          break;

        --count;
        --cooling;
        --totalTasks;
        ++ans;
      }

      if (totalTasks)
        ans += cooling;

      sort(freq.rbegin(), freq.rend());
    }

    return ans;
  }
};

int main() {
  Solution s;
  vector<char> tasks;

  cout << "Test Case 1:" << endl;
  tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  cout << s.leastInterval(tasks, 2) << endl;

  cout << "Test Case 2:" << endl;
  tasks = {'A', 'C', 'A', 'B', 'D', 'B'};
  cout << s.leastInterval(tasks, 1) << endl;

  cout << "Test Case 3:" << endl;
  tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  cout << s.leastInterval(tasks, 3) << endl;

  cout << "Test Case 4:" << endl;
  tasks = {
      'O', 'C', 'H', 'Y', 'B', 'O', 'G', 'K', 'O', 'Z', 'J', 'C', 'T', 'G', 'B',
      'X', 'S', 'Y', 'L', 'N', 'A', 'T', 'A', 'Y', 'V', 'I', 'O', 'T', 'C', 'A',
      'U', 'L', 'H', 'O', 'G', 'I', 'M', 'T', 'X', 'X', 'U', 'E', 'I', 'K', 'P',
      'V', 'S', 'W', 'Z', 'A', 'G', 'H', 'G', 'O', 'Y', 'B', 'G', 'L', 'U', 'W',
      'Z', 'M', 'R', 'O', 'J', 'L', 'S', 'L', 'I', 'O', 'Q', 'Y', 'J', 'P', 'Q',
      'P', 'P', 'D', 'K', 'A', 'P', 'G', 'F', 'X', 'I', 'K', 'T', 'V', 'Y', 'H',
      'N', 'P', 'Y', 'J', 'E', 'D', 'D', 'U', 'Q', 'H', 'P', 'X', 'X', 'I', 'U',
      'O', 'M', 'C', 'F', 'Q', 'L', 'I', 'R', 'H', 'G', 'L', 'V', 'V', 'L', 'U',
      'P', 'Q', 'G', 'Z', 'U', 'Z', 'N', 'T', 'V', 'V', 'M', 'W', 'S', 'D', 'L',
      'F', 'R', 'I', 'P', 'Y', 'V', 'V', 'I', 'Y', 'V', 'S', 'A', 'Z', 'K', 'L',
      'H', 'V', 'O', 'W', 'F', 'W', 'M', 'W', 'P', 'G', 'F', 'M', 'G', 'L', 'Y',
      'M', 'M', 'V', 'D', 'A', 'O', 'E', 'H', 'R', 'P', 'W', 'Q', 'W', 'I', 'Q',
      'R', 'I', 'M', 'C', 'V', 'K', 'R', 'V', 'F', 'U', 'C', 'R', 'Y', 'K', 'F',
      'F', 'Y', 'J', 'F', 'L', 'H', 'R', 'E', 'J', 'R', 'S', 'I', 'R', 'R', 'K',
      'O', 'F', 'W', 'X', 'A', 'S', 'R', 'C', 'Y', 'F', 'D', 'U', 'J', 'W', 'R',
      'J', 'V', 'N', 'N', 'G', 'M', 'X', 'E', 'X', 'Y', 'B', 'Y', 'H', 'W', 'B',
      'N', 'K', 'M', 'M', 'B', 'P', 'C', 'F', 'K', 'V', 'S', 'A', 'T', 'Q', 'W',
      'N', 'G', 'R', 'D', 'X', 'M', 'D', 'P', 'R', 'K', 'I', 'R', 'H', 'W', 'Z',
      'F', 'S', 'S', 'W', 'E', 'R', 'J', 'P', 'T', 'R', 'K', 'C', 'X', 'K', 'J',
      'J', 'T', 'B', 'Z', 'L', 'A', 'C', 'D', 'H', 'P', 'Q', 'J', 'M', 'D', 'Y',
      'H', 'V', 'O', 'B', 'G', 'F', 'J', 'R', 'S', 'Q', 'G', 'Y', 'D', 'A', 'G',
      'C', 'B', 'T', 'T', 'K', 'S', 'R', 'R', 'P', 'X', 'Z', 'J', 'A', 'N', 'J',
      'G', 'R', 'G', 'P', 'F', 'Z', 'V', 'N', 'K', 'F', 'N', 'E', 'I', 'O', 'X',
      'L', 'N', 'W', 'J', 'X', 'U', 'H', 'H', 'B', 'P', 'B', 'I', 'K', 'Y', 'L',
      'T', 'J', 'O', 'Q', 'X', 'R', 'Q', 'I', 'H', 'P', 'T', 'D', 'B', 'Z', 'Z',
      'D', 'D', 'O', 'S', 'X', 'J', 'G', 'C', 'T', 'B', 'R', 'A', 'G', 'L', 'M',
      'I', 'Y', 'E', 'G', 'W', 'Q', 'K', 'V', 'N', 'Q', 'Q', 'Q', 'S', 'U', 'E',
      'T', 'L', 'W', 'U', 'F', 'P', 'U', 'R', 'G', 'X', 'X', 'E', 'T', 'R', 'M',
      'D', 'Q', 'Y', 'V', 'N', 'F', 'A', 'X', 'R', 'V', 'Z', 'M', 'Y', 'G', 'Y',
      'E', 'P', 'Y', 'B', 'P', 'W', 'R'};
  cout << s.leastInterval(tasks, 20) << endl;
}
