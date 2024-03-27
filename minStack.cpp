#include <stack>

using namespace std;

class MinStack {
  stack<pair<int, int>> s;

public:
  MinStack() {}

  void push(int val) {
    int minValue = min(val, s.top().second);
    s.push({val, minValue});
  }

  void pop() { s.pop(); }

  int top() { return s.top().first; }

  int getMin() { return s.top().second; }
};
