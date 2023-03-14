// Brute Force

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while(t1 != NULL){
            t2 = headB;
            while(t2 != NULL){
                if(t1 == t2)
                    return t1;
                t2 = t2->next;
            }
            t1 = t1->next;
        } 
        return NULL;  
    }
};


// Better Soln

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> m;

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while(t1 != NULL){
            m[t1] = t1->val;
            t1 = t1->next;
        }

        for(t2 = headB; t2 != NULL; t2 = t2->next){
            if(m.find(t2) != m.end()){
                return t2;
            }
        } 

        return NULL;  
    }
};


// Optimal - 1
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* t1 = headA;
        ListNode* t2 = headB;
        int l1 = 0, l2 = 0;

        while(t1 != NULL || t2 != NULL){

            if(t1 != NULL){
                l1 += 1;
                t1 = t1->next;
            }

            if(t2 != NULL){
                l2 += 1;
                t2 = t2->next;
            }
            
        } 

        int diff = l1 - l2;

        if(diff < 0){
            t2 = headB;
            for(int i = 1; i <= -1*diff; i++)
                t2 = t2->next;

            t1 = headA;

            while(t1 != t2){
                t1 = t1->next;
                t2 = t2->next;
            }

        }
        else{
            t1 = headA;
            for(int i = 1; i <= diff; i++)
                t1 = t1->next;

            t2 = headB;

            while(t1 != t2){
                t1 = t1->next;
                t2 = t2->next;
            }
        }

        return t1;
          
    }
};

// Best or Optimal - 2

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while(t1 != t2){
            t1 = t1 == NULL ? headB : t1->next;
            t2 = t2 == NULL ? headA : t2->next;
        } 

        return t1;  
    }
};
