// Brute Force Soln:

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
    bool hasCycle(ListNode *head) {
        
        if(head == NULL || head->next == NULL)
            return 0;

        unordered_map<ListNode*, int> m;
        ListNode* temp = head;

        while(temp){
            if(m.find(temp) != m.end())
                return 1;
            
            m[temp] = temp->val;
            temp = temp->next;
        }
        
        return 0;
    }
};

// Optimal Soln:

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
    bool hasCycle(ListNode *head) {
        
        if(head == NULL || head->next == NULL)
            return 0;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return 1;
        }
        
        return 0;
    }
};
