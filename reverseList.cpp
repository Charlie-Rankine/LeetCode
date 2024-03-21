#include "TreeNode.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *nextNode, *prevNode = nullptr;

    while (head) {
      nextNode = head->next;
      head->next = prevNode;
      prevNode = head;
      head = nextNode;
    }

    return prevNode;
  }
};

int main() {}
