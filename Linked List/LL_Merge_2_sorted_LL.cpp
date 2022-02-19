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

Node* mergeSorted(Node* &head1, Node* &head2){
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    Node* dummyNode = new Node(-1);
    Node* ptr3 = dummyNode;

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data < ptr2->data){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }

        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }

        ptr3 = ptr3->next;
    } 

    while(ptr1!=NULL){
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }

    while(ptr2!=NULL){
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }

    return dummyNode->next;

}

Node* mergeRecursiveSorted(Node* &head1, Node* &head2){
    if(head1==NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    
    Node* result;
    if(head1->data < head2->data){
        result = head1;
        result->next = mergeRecursiveSorted(head1->next, head2);
    }
    else{
        result = head2;
        result->next = mergeRecursiveSorted(head1, head2->next);
    }

    return result;
}

int main(){
    int arr1[] = {1, 4, 5, 7};
    int arr2[] = {2, 3, 6};

    Node* head1 = NULL;
    Node* head2 = NULL;

    for(int i=0; i<4; i++){
        insertatTail(head1, arr1[i]);
    }

    for(int i=0; i<3; i++){
        insertatTail(head2, arr2[i]);
    }

    display(head1);
    display(head2);

    Node* newHead = mergeRecursiveSorted(head1, head2);
    display(newHead);
}