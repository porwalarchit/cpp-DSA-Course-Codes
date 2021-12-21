#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

vector<int> postOrder(struct Node* root){
    vector<int> ans;
    if(root==NULL)
        return ans;
    
    stack<Node*> stk;
    Node* curr = root;

    while(curr!=NULL || !stk.empty()){
        if(curr!=NULL){
            stk.push(curr);
            curr = curr->left;
        }

        else{
            Node* temp = stk.top()->right;
            if(temp==NULL){
                temp = stk.top();
                stk.pop();
                ans.push_back(temp->data);

                while(!stk.empty() && (temp == stk.top()->right)){
                    temp = stk.top();
                    stk.pop();
                    ans.push_back(temp->data);
                }
            }
            
            else{
                curr = temp;
            }
        }
    }
    return ans;
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);

    root->left->left = new Node(3);
    root->right->left = new Node(8);

    root->left->left->right = new Node(4);
    root->left->left->right->right = new Node(5);
    root->left->left->right->right->right = new Node(6);

    vector<int> ans = postOrder(root);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

}