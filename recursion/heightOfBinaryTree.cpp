#include<bits/stdc++.h>

using namespace std;

class TreeNode{

public:
    int val;
    TreeNode *left,*right;

    TreeNode(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

int height(TreeNode *root){

    // base condition
    if(root==nullptr)
        return 0;
    int l = height(root->left);
    int r = height(root->right);

    return 1+max(l,r);
}

int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(6);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(3);

    cout<<"Height of Tree:->"<<height(root)<<"\n";

}
