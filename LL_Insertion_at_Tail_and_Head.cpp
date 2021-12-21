#include<iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* Next;

    Node(int val){
        data = val;
        Next = NULL;
    }
};

void InsertatHead(Node* &Head, int val) {
    Node* n = new Node(val);
    n -> Next = Head;
    Head = n;
}

void InsertatTail(Node* &Head, int val){
    Node* n = new Node(val);
    if(Head == NULL){
        Head = n;
        return;
    }
    
    Node* temp = Head;
    while(temp->Next != NULL){
        temp = temp->Next;
    }
    temp -> Next = n;
}

void display(Node* Head){
    Node* temp = Head;
    while(temp != NULL)
    {
        cout<<(temp->data)<<"->";
        temp = temp->Next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* Head = NULL;
    display(Head);

    //Insertion at Tail
    InsertatTail(Head, 1);
    display(Head);
    InsertatTail(Head, 2);
    display(Head);
    InsertatTail(Head, 3);
    display(Head);

    //Insertion at Head
    InsertatHead(Head, 4);
    display(Head);
    
}
