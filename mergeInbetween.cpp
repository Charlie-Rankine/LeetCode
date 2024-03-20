#include "TreeNode.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    ListNode *head = list1;
    ListNode *cut;

    for (int i = 0; i < a - 1; ++i)
      list1 = list1->next;
    cut = list1;

    for (int i = 0; i <= b - a + 1; ++i)
      list1 = list1->next;

    cut->next = list2;

    while (list2->next)
      list2 = list2->next;

    list2->next = list1;

    return head;
  }
};

int main() {}
