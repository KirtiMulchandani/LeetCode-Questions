// Brute Force

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        Node* temp = head;

        while(temp != NULL){
            m[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(temp != NULL){
            m[temp]->next = m[temp->next];
            m[temp]->random = m[temp->random];
            temp = temp->next;
        }

        return m[head];
    }
};

// Optimal

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;

        // first step: To create deep copy nodes between the nodes of original LL

        while(temp != NULL){
            Node* n = new Node(temp->val);
            n->next = temp->next;
            temp->next = n;
            temp = temp->next->next;
        }

        // second step: To arrange the random ptr of deep nodes according to original LL

        temp = head;

        while(temp != NULL){
            if(temp->random != NULL)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        // Third step: To get back the original LL and deep copy LL

        Node* d = new Node(0);
        Node* x = d;
        temp = head;
        Node* front;

        while(temp != NULL){
            front = temp->next->next;
            x->next = temp->next;

            temp->next = front;
            x = x->next;
            temp = front;

        }

        return d->next;
    }
};
