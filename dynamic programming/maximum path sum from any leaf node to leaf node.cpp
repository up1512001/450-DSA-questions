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

int maximumPathSumLeaf(Node *root,int &res){

    if(root==nullptr){
        return 0;
    }

    int l = maximumPathSumLeaf(root->left,res);
    int r = maximumPathSumLeaf(root->right,res);

    int temp = max(l,r) + root->val;

    if(root->left==nullptr && l==0){
        temp=r+root->val;
    }
    if(root->right==nullptr && r==0){
        temp = l+root->val;
    }

    int ans = l + r + root->val;
    res = max(res,ans);

    cout<<"l:"<<l<<" r:"<<r<<" ans:"<<ans<<" temp:"<<temp<<" res:"<<res<<"\n";

    return temp;

}

int main(){

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(-55);
    root->left->left->left = new Node(50);

    int res = INT_MIN;

    maximumPathSumLeaf(root,res);

    cout<<"Maximum sum from any leaf node to leaf node is :->"<<res<<"\n";


}
