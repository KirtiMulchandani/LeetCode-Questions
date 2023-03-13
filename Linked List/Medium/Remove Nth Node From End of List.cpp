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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* d = new ListNode();
        d->next = head;
        
        ListNode* fast = d;
        ListNode* slow = d;

        for(int i = 1; i <= n; i++)
            fast = fast->next;
        
        while(fast && fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }


        slow->next = slow->next->next;

        return d->next;

    }
};
