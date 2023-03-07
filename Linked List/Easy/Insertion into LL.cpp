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

    display(head);

}
