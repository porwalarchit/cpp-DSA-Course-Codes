#include<iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void InsertatTail(Node* &head, int val){
    Node* n = new Node(val);
    if(head==NULL){
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void display(Node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

Node* reverse(Node* &head){
    Node* prevptr = NULL;
    Node* currptr = head;
    Node* nextptr;

    while(currptr!=NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

Node* reverseRecursive(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

int main(){
    Node* head = NULL;
    InsertatTail(head, 1);
    InsertatTail(head, 2);
    // InsertatTail(head, 3);
    // InsertatTail(head, 4);
    display(head);

    cout<<"\nReverse Linked List: "<<endl;
    Node* newhead = reverse(head);
    display(newhead);

    cout<<"\nReverse Linked List using Recursion: "<<endl;
    Node* newHead = reverse(newhead);
    display(newHead);


}