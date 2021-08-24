#include<bits/stdc++.h>
using namespace std;

class Node{
public :
    Node *left,*right;
    int val;
    Node(int val){
        this->val = val;
        this->left=nullptr;
        this->right=nullptr;
    }
};


int diameterOfBinaryTree(Node *root,int &res){

    if(root==nullptr){
        return 0;
    }

    int l = diameterOfBinaryTree(root->left,res);
    int r = diameterOfBinaryTree(root->right,res);

    int temp = 1+max(l,r);
    int ans = 1+l+r;
    cout<<"l:"<<l<<" r:"<<r<<"\n";
    res = max(res,ans);
    cout<<"ans:"<<ans<<" res:"<<res<<"\n";

    return temp;

}


int main(){

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->left->left = new Node(50);

    int res = INT_MIN;
    diameterOfBinaryTree(root,res);
    cout<<"Diameter of Binary Tree is :->"<<res<<"\n";


}
