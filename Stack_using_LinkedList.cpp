//Implementation of Stack using Linked List

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

class Stack{
    public:
    Node* top;
    Stack(){
        top = NULL;
    }
};

void push(Stack &s, int val){
    Node* n = new Node(val);
    if(n == NULL){
        cout<<"Not able to push the Element\n";
        return;
    }
    cout<<n->data<<" pushed to stack\n";
    n->next = s.top;
    s.top = n;
}

void pop(Stack &s){
    if(s.top==NULL){
        cout<<"No element to pop\n";
        return;
    }
    Node* todelete = s.top;
    cout<<todelete->data<<" popped from stack\n";
    s.top = s.top->next;
    delete todelete;
}

int Top(Stack s){
    if(s.top == NULL){
        cout<<"No element in stack ";
        return -1;
    }
    cout<<"Top Element of Stack is: ";
    return (s.top->data);
}

bool isEmpty(Stack s){
    cout<<"Is Stack Empty: ";
    return (s.top==NULL);
}

void display(Stack s){
    cout<<"Elements present in stack :";
    while(s.top!=NULL){
        cout<<s.top->data<<"->";
        s.top = s.top->next;
    }
    cout<<"NULL\n\n";
}

int main(){
    Stack s;
    cout<<isEmpty(s)<<endl;
    push(s,3);
    push(s, 11);
    push(s,30);

    cout<<Top(s)<<endl;   
    display(s);

    pop(s);
    cout<<Top(s)<<endl;   
    display(s);
    cout<<isEmpty(s)<<endl;

    pop(s);
    pop(s);
    pop(s);
    display(s);
    cout<<Top(s)<<endl;   
    cout<<isEmpty(s)<<endl;
}