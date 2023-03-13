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
    void insertAtHead(ListNode* &head, int data){

    ListNode* n = new ListNode(data);

    n->next = head;
    head = n;

    }

    void insertAtTail(ListNode* &head, int data){
        ListNode* n = new ListNode(data);
        ListNode* temp = head;

        if(head == NULL){
            insertAtHead(head, data);
            return;
        }

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = n;
        
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* head = NULL;
    
        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                insertAtTail(head, list1->val);
                list1 = list1->next;
            }
            else{
                insertAtTail(head, list2->val);
                list2 = list2->next;
            }
        }

        while(list1 != NULL){
            insertAtTail(head, list1->val);
            list1 = list1->next;
        }

        while(list2 != NULL){
            insertAtTail(head, list2->val);
            list2 = list2->next;
        }

        return head;
    }
};
