#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=right=NULL;
    }
};

vector<int> PostOrder(Node* root){
    vector<int> ans;
    if(root==NULL)
        return ans;
    stack<Node*> st1, st2;
    Node* node = root;
    st1.push(node);

    while(!st1.empty()){
        node = st1.top();
        st1.pop();
        st2.push(node);

        if(node->left!=NULL){
            st1.push(node->left);
        }

        if(node->right!=NULL)
            st1.push(node->right);
    }

    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}

int main(){
    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->left->right = new Node(7);
    root->right->left->right->right = new Node(8);

    vector<int> ans = PostOrder(root);
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
}