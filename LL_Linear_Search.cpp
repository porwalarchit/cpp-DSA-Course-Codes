#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void InsertatTail(Node* &Head, int val){
    Node* n = new Node(val);
    if(Head == NULL){
        Head = n;
        return;
    }

    Node* temp = Head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

bool linearSearch(Node* head, int key){
    while(head != NULL){
        if(head->data == key)
            return 1;
        head = head->next;
    }
    return 0;
}

void display(Node* Head){
    while(Head != NULL){
        cout<<Head->data<<"->";
        Head = Head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = NULL;
    InsertatTail(head, 1);
    InsertatTail(head, 2);
    InsertatTail(head, 3);
    InsertatTail(head, 4);
    display(head);

    cout<<linearSearch(head, 2);
    cout<<endl;
    cout<<linearSearch(head, 5);
}