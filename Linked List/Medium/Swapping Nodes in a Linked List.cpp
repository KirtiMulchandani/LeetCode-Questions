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
    ListNode* swapNodes(ListNode* head, int k) {
        int len = 0;
        ListNode* temp1 = head;
        ListNode* temp2 = head;

        for(auto i = head; i != NULL; i = i->next){
            temp2 = temp2 == NULL ? NULL : temp2->next;
            if(--k == 0){
                temp1 = i;
                temp2 = head;
            }
        }
        
        swap(temp1->val, temp2->val);
        return head;

    }
};
