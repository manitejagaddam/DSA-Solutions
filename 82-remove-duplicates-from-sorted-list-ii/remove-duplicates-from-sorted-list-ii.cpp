class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            // move curr while the next node has same value
            bool dup = false;
            while (curr->next && curr->val == curr->next->val) {
                curr = curr->next;
                dup = true;
            }

            if (dup) {
                // skip the entire duplicate block
                prev->next = curr->next;
            } else {
                // no duplicates, safe to move prev
                prev = prev->next;
            }
            curr = curr->next;
        }

        return dummy->next;
    }
};
