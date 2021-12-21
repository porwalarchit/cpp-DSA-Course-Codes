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

void insertatHead(Node* &head, int val){
    Node* n =new Node(val);
    if(head==NULL){
        n->next = n;
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertatTail(Node* &head, int val){
    
    if(head==NULL){
        insertatHead(head, val);
        return;
    }

    Node* n = new Node(val);
    Node* temp = head;

    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void display(Node* head){
    Node* temp = head;
    do{
        cout<<temp->data<<"->";
        temp = temp->next;
    }while (temp!=head);
    
    cout<<"Head"<<endl;
}

void deleteatHead(Node* &head){
    if(head->next==head)//For case when only one element is there and it needs to be deleted;
    {
        Node* todelete = head;
        head=NULL;
        delete todelete;
        cout<<"List is Empty\n";
        return;
    }

    Node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }

    Node* todelete = head;
    
    temp->next = head->next;
    head = head->next;
    delete todelete;

}

void deletion(Node* &head, int pos){
    if(pos==1){
        deleteatHead(head);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count!=pos-1){
        temp = temp->next;
        count++;
    }

    Node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

int main(){
    Node* head = NULL;
    insertatTail(head, 1);
    insertatTail(head, 2);
    insertatTail(head, 3);
    insertatTail(head, 4);
    display(head);

    insertatHead(head, 5);
    display(head); 

    deletion(head, 4);
    display(head);

    deletion(head, 1);
    display(head);

    return 0;
}