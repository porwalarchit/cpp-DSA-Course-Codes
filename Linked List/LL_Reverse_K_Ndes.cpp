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

void insertatTail(Node* &head, int val){
    Node* n = new Node(val);
    if(head == NULL){
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

Node* reverseK(Node* head, int k){
    Node* prevptr = NULL;
    Node* currptr = head;
    Node* nextptr;
    int count = 0;

    while(currptr!=NULL && count<k){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if(nextptr!=NULL)
        head->next = reverseK(nextptr, k);
    
    return prevptr;
}

int main(){
    Node* head = NULL;
    insertatTail(head, 1);
    insertatTail(head, 2);
    insertatTail(head, 3);
    insertatTail(head, 4);
    insertatTail(head, 5);
    insertatTail(head, 6);
    cout<<"Original Linked List: \n";
    display(head);

    
    int k;
    cout<<"Enter k: ";
    cin>>k;
    cout<<"After Reversing "<<k<<" Nodes: \n";
    Node* newhead = reverseK(head, k);
    display(newhead);

}