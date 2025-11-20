/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = new ListNode(0);
        ListNode* moreHead = new ListNode(0);

        ListNode* less = lessHead;
        ListNode* more = moreHead;

        ListNode* curr = head;

        while (curr) {
            if (curr->val < x) {
                less->next = curr;
                less = less->next;
            } else {
                more->next = curr;
                more = more->next;
            }
            curr = curr->next;
        }

        more->next = nullptr;

        less->next = moreHead->next;

        return lessHead->next;
    }
};
