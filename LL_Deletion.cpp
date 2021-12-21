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
    if(head == NULL){
        head = n;
        return;
    }

    Node* tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = n;
}

void deletionatHead(Node* &head){
    Node* todelete = head;
    head = head->next;
    delete todelete;
}

void deletion(Node* &head, int val){
    if(head==NULL)
        return;
    
    cout<<"Deleting "<<val<<": "<<endl;

    if(head->next == NULL || head->data == val){
        deletionatHead(head);
        return;
    }

    Node* temp = head;
    while(temp->next->data != val){
        temp = temp -> next;
    }
    
    Node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void display(Node* head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl<<endl;
}

int main(){
    Node* head = NULL;
    InsertatTail(head, 1);
    InsertatTail(head, 2);
    InsertatTail(head, 3);
    InsertatTail(head, 4);
    display(head);

    
    deletion(head, 4);
    display(head);
    deletion(head, 1);
    display(head);
    deletion(head, 2);
    display(head);
    deletion(head, 3);
    display(head);

}