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


    ListNode* Reverse(ListNode * head){
        ListNode * curr = head;
        ListNode * prev = nullptr;
        ListNode * next = nullptr;
        while(curr){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
       if(k == 1 || !head) return head;
       ListNode * dummy = new ListNode(-1);
       dummy -> next = head;
       ListNode * pre = dummy;
       ListNode * end = dummy;
       while(end -> next){

        for(int i = 0 ; i < k && end != nullptr ; i++){
            end = end -> next;
        }

        if(end == nullptr) break;

        ListNode * start = pre -> next;
        ListNode * next = end -> next;

        end -> next = nullptr;

        pre -> next = Reverse(start);

        start -> next = next;
        
        pre = start;
        end = start;
       }

       return dummy -> next;

    }
};