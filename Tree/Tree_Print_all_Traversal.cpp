#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left=right=NULL;
    }
};

void printAllTraversal(struct Node* root){
    stack<pair<Node*, int>> st;
    st.push({root, 1});
    vector<int> pre, in, post;
    
    if(root==NULL)
        return;
    
    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left!=NULL){
                st.push({it.first->left, 1});
            }
        }

        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right!=NULL){
                st.push({it.first->right, 1});
            }
        }

        else {
            post.push_back(it.first->data);
        }
    }

    cout<<"PreOrder: ";
    for(auto i:pre)
        cout<<i<<" ";
    cout<<endl;

    cout<<"InOrder: ";
    for(auto i:in)
        cout<<i<<" ";
    cout<<endl;

    cout<<"PostOrder: ";
    for(auto i:post)
        cout<<i<<" ";
    cout<<endl;
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);

    root->left->left = new Node(3);
    root->right->left = new Node(6);

    root->left->right = new Node(4);
    root->right->right = new Node(7);

    printAllTraversal(root);
}
