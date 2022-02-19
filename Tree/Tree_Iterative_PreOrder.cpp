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

vector<int> PreOrder(Node* root){
    vector<int> ans;
    if(root==NULL)
        return ans;
    
    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        root = st.top();
        st.pop();
        ans.push_back(root->data);

        if(root->right!=NULL)
            st.push(root->right);
        if(root->left!=NULL)
            st.push(root->left);
    }
    return ans;
}

int main(){
    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(7);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);

    vector<int> ans = PreOrder(root);
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
}