#include "TreeNode.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  ListNode *removeZeroSumSublists(ListNode *head) {
    // Return nullptr if the head is nullptr
    if (!head)
      return nullptr;

    // Create a new node that will be looped and a sum variable
    ListNode *current = head;
    int sum = 0;

    // Until nullptr, move through the list, increasing the sum
    while (current) {
      sum += current->val;

      if (!sum) {
        head = current->next;
        return removeZeroSumSublists(head);
      }

      current = current->next;
    }

    // Perform the final removal
    head->next = removeZeroSumSublists(head->next);

    return head;
  }
};

int main() {}
