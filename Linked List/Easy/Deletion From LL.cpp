#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }

    ~node(){
        int val = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "Node with value: " << val << "has been deleted"  << endl;
    }

};


void insertAtHead(node* &head, int data){

    node* n = new node(data);

    n->next = head;
    head = n;

}

void insertAtTail(node* &head, int data){
    node* n = new node(data);
    node* temp = head;

    if(head == NULL){
        insertAtHead(head, data);
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    
}


void insertAtPos(node* &head, int data, int pos){
    int cnt = 1;
    node* curr = head;
    node* prev = NULL;

    if(pos == 1){
        insertAtHead(head, data);
        return;
    }

    while(cnt < pos){
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    node* n = new node(data);

    prev->next = n;
    n->next = curr;

    curr->next = NULL;
    delete curr;

}

void deleteHead(node* &head){
    if(head != NULL){
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }


    cout << "Nothing can be deleted" << endl;
    return;
}

void deleteAtPos(node* &head, int pos){
    if(pos == 1){
        deleteHead(head);
        return;
    }

    int cnt = 1;
    node* curr = head;
    node* prev = NULL;

    while(cnt < pos){
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    prev->next = curr->next;

    curr->next = NULL;
    delete curr;
    
    

}

void display(node* head){
    if(head == NULL)
        cout << "nothing to print" << endl;

    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    
}

int main(){
    node* head = NULL;
    display(head);
    
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);

    insertAtTail(head, 10);

    insertAtPos(head, 15, 1);
    deleteHead(head);

    deleteAtPos(head, 3);

    display(head);

}
