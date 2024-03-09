#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (!head)
      return false;

    ListNode *fast = head->next;
    ListNode *slow = head;

    while (true) {
      if (!fast || !fast->next)
        return false;

      if (fast == slow)
        return true;

      fast = fast->next->next;
      slow = slow->next;
    }
  }
};
