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

void insertatTail(Node* &head, int val){
    Node* n = new Node(val);
    if(head==NULL){
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = n;
}

void display(Node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL\n";
}

int length(Node* head){
    int l=0;
    while(head!=NULL){
        l++;
        head = head->next;
    }
    // cout<<l<<endl;
    return l;
}

void intersect(Node* &head1, Node* &head2, int pos){
    Node* temp1 = head1;
    pos--;
    while(pos--){
        temp1 = temp1->next;
    }

    Node* temp2 = head2;
    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }

    temp2->next = temp1;
}

int intersectionPoint(Node* &head1, Node* &head2){
    int l1 = length(head1);
    int l2 = length(head2);

    Node* ptr1;
    Node* ptr2;

    Node* temp = head1;
    int d=0;
    
    if(l1>l2){
        d = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }

    else{
        d = l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while(d){
        ptr1 = ptr1->next;
        if(ptr1==NULL)
            return -1;
        d--;
    }

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1 == ptr2)
            return ptr1->data;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

int main(){
    int arr1[] = {1,2,3,4,5,6};
    int arr2[] = {9,10};
    
    Node* head1 = NULL;
    Node* head2 = NULL;

    for(int i=0; i<6; i++){
        insertatTail(head1, arr1[i]);
    }

    for(int i=0; i<2; i++){
        insertatTail(head2, arr2[i]);
    }

    display(head1);
    // display(head2);

    intersect(head1,head2, 5);
    display(head2);

    cout<<intersectionPoint(head1, head2);
}