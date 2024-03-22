#include "TreeNode.cpp"
#include <string>

using namespace std;

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    string s = "";

    while (head) {
      s += head->val;
      head = head->next;
    }

    for (int i = 0, j = s.size() - 1; i < s.size() / 2; ++i, --j)
      if (s[i] != s[j])
        return false;

    return true;
  }
};

int main() {}
