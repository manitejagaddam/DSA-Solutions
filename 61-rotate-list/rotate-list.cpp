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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0) return head;
        int len {1};
        ListNode * tail = head;
        while(tail -> next){
            tail = tail -> next;
            len++;
        }
        cout << len;
        k = k % len;
        if(k == 0) return head;
        int reqLen {len - k};
        ListNode * tempHead = head;
        ListNode * prevHead = head;

        while(reqLen--){
            prevHead = tempHead;
            tempHead = tempHead -> next;
        }

        prevHead -> next = nullptr;
        tail -> next = head;
        return tempHead;


    }
};