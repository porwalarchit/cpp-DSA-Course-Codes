#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};


void insertatHead(Node* &head, int val){
    Node* n = new Node(val);
    n->next = head;
    if(head!=NULL)
        head->prev = n;
    head=n;
}

void insertatTail(Node* &head, int val){
    if(head==NULL){
        insertatHead(head, val);
        return;
    }

    Node* n = new Node(val);

    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;
}

void display(Node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

void deleteatHead(Node* &head){
    Node* todelete = head;
    head = head->next;
    head -> prev = NULL;
    delete todelete;
}

void deletion(Node* &head, int pos){
    if(pos==1){
        deleteatHead(head);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(temp!=NULL && count!=pos){
        temp = temp->next;
        count++;
    }

    temp->prev->next = temp->next;
    if(temp->next!=NULL)//Because there is no previous of NULL
    {
        temp->next->prev = temp->prev;
    }
    delete temp;


}

int main(){
    Node* head = NULL;
    insertatTail(head, 1);
    insertatTail(head, 2);
    insertatTail(head, 3);
    insertatTail(head, 4);
    display(head);

    insertatTail(head, 5);
    display(head);

    insertatHead(head, 6);
    display(head);

    deletion(head, 3);
    display(head);

    deletion(head, 1);
    display(head);
    
    deleteatHead(head);
    display(head);
}