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
void InsertatHead(Node* &head, int val){
    Node* n = new Node(val);
    n->next = head;
    head = n;
}
void display(Node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

void makeCycle(Node* &head, int pos){
    Node* temp = head;
    Node* startNode;

    int count = 1;

    while(temp->next!=NULL){
        if(count==pos)
            startNode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

bool detectCycle(Node* &head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL)/*We will check for 
    case when there is no cycle (fast is always ahead of slow)*/
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast){
            return true;
        }
    }
    return false;
}

void removeCycle(Node* &head){
    Node* slow = head;
    Node* fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }while (slow!=fast);
    
    slow = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

int main(){
    Node* head = NULL;
    
    for(int i=9; i>0; i--){
        InsertatHead(head, i);
    }
    makeCycle(head, 4);
    // display(head);

    cout<<detectCycle(head)<<endl;

    if(detectCycle){
        removeCycle(head);
        cout<<detectCycle(head)<<endl;
        display(head);
    }
}