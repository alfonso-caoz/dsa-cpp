/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Floyd´s cycle finding algorithm or Hare and Tortoise Algorithm
    // Time complexity O(n). Space complexity O(1).
    bool hasCycle(ListNode* head) {

        ListNode* tortoise = head;
        ListNode* hare = head;

        while (hare != nullptr && hare->next != nullptr) {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise == hare) return true;
        }

        return false;

    }
};
