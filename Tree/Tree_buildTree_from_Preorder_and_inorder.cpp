#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int Search(int inorder[], int start, int end, int val){
    for(int i = start; i<=end; i++){
        if(inorder[i] == val)
            return i;
    }
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int start, int end){
    static int idx = 0;
    if(start>end)
        return NULL;
    
    int val = preorder[idx];
    idx++;
    Node* curr = new Node(val);

    if(start==end)
        return curr;

    int pos = Search(inorder, start, end, val);
    curr->left = buildTree(preorder, inorder, start, pos-1);
    curr->right = buildTree(preorder, inorder, pos+1, end);
    return curr;
}

void inOrder(Node* root){
    if(root==NULL)
        return;
    
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main(){
    int preorder[] = {4, 2, 1, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    Node* root = buildTree(preorder, inorder, 0, 4);
    inOrder(root);
}