#include "TreeNode.cpp"

using namespace std;

class Solution {
public:
  void reorderList(ListNode *head) {
    if (!head || !head->next || !head->next->next)
      return;

    ListNode *fast = head;
    while (fast->next->next)
      fast = fast->next;

    fast->next->next = head->next;
    head->next = fast->next;

    fast->next = nullptr;

    reorderList(head->next->next);
  }
};

int main() {}
