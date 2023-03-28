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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        if(head->next->next == NULL) return head;

        ListNode* evenHead = NULL;
        ListNode* evenTail = NULL;
        ListNode* oddHead = NULL;
        ListNode* oddTail = NULL;
        int cnt = 1;

        while(head != NULL){
            if(cnt % 2 == 1){
                if(oddHead == NULL){
                    oddHead = head;
                    oddTail = head;
                }
                else{
                    oddTail->next = head;
                    oddTail = oddTail->next;
                }
            }
            else{
                 if(evenHead == NULL){
                    evenHead = head;
                    evenTail = head;
                }
                else{
                    evenTail->next = head;
                    evenTail = evenTail->next;
                }               
            }
            head = head->next;
            cnt++;
        }

        evenTail->next = NULL;
        oddTail->next = evenHead;

        return oddHead;
    }
};
