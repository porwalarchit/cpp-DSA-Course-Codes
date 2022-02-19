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

vector<int> InOrder(Node* root){
    vector<int> ans;
    Node* node = root;

    stack<Node*> st;struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=right=NULL;
    }
};

    while(true){
        if(node!=NULL){
            st.push(node);
            node = node->left;
        }

        else{
            if(st.empty())
                break;
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            node = node->right;
        }
    }
    return ans;
}

int main(){
    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    vector<int> ans = InOrder(root);
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
}