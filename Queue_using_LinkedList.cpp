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

class Queue{
    Node* front;
    Node* back;

    public:
    Queue(){
        front = NULL;
        back = NULL;
    }

    void Enqueue(int x){
        Node* n = new Node(x);
        if(front == NULL){
            front = n;
            back = n;
            return;
        }

        back->next = n;
        back = n;
    }

    void Dequeue(){
        if(front==NULL){ 
            cout<<"No element in queue"<<endl;
            return;
        }

        Node* todelete = front;
        front = front->next;
        delete todelete;
    }

    int peek(){
        if(front==NULL){
            cout<<"No element in queue"<<endl;
            return -1;
        }

        return front->data;
    }

    bool isEmpty(){
        if(front==NULL)
            return true;
        return false;
    }
};

int main(){
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);

    while(!q.isEmpty()){
        cout<<q.peek()<<" ";
        q.Dequeue();
    }
}