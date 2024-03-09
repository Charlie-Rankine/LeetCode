#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast) {
      fast = fast->next;

      if (!fast) {
        return slow;
      }

      slow = slow->next;
      fast = fast->next;
    }

    return slow;
  }
};
