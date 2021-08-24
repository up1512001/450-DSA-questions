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

int maximumPathSumAny(Node *root,int &res){

    if(root==nullptr){
        return 0;
    }

    int l = maximumPathSumAny(root->left,res);
    int r = maximumPathSumAny(root->right,res);

    int temp = max(max(l,r),root->val);
    int ans = max(l+r+root->val,root->val);
    res = max(res,ans);

    return ans;
}

int main(){

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(-55);
    root->left->left->left = new Node(50);

    int res = INT_MIN;

    maximumPathSumAny(root,res);

    cout<<"Maximum sum from any node to any node is :->"<<res<<"\n";


}
