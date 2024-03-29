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
    ListNode* rotate(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }

        temp->next = head;
        prev->next = NULL;
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        
        int len = 1;

        ListNode* temp = head;

        while (temp->next != NULL){
            temp = temp->next;
            len++;
        }

        temp->next = head;

        k = k % len;
        k = len - k;

        while(k--){
            temp = temp->next;
        }

        head = temp->next;
        temp->next = NULL;
        return head;
    }
};
