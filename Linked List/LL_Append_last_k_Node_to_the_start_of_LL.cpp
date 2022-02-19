#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertatTail(Node* &head, int val){
    Node* n = new Node(val);
    if(head==NULL){
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp ->next;
    }

    temp->next = n;
}

void display(Node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL\n";
}

int Length(Node* head){
    int l=0;
    while(head!=NULL){
        l++;
        head = head->next;
    }
    // cout<<l<<endl;
    return l;
}

Node* AppendKatStart(Node* &head, int k){
    Node* newHead;
    Node* newTail;
    Node* tail = head;

    int l = Length(head);
    k = k%l; // For case when k>l 
    int count = 1;
    while(tail->next!=NULL){
        if(count == l-k)
            newTail = tail;
        if(count == l-k+1)
            newHead = tail;
        
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

int main(){
    Node* head = NULL;
    for(int i=1; i<=6; i++)
        insertatTail(head, i);
    display(head);

    Node* newHead = AppendKatStart(head, 3);
    display(newHead);
}