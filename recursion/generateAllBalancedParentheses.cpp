#include<bits/stdc++.h>
using namespace std;

void parentheses(int o,int c,vector<string>&ans,string op=""){

    if(o==0 && c==0){
        ans.push_back(op);
     //   cout<<op<<"\n";
        return;
    }
    if(op.empty()){
        op+='(';
        parentheses(o-1,c,ans,op);
        return;
    }
    if(o==0){
        op+=')';
        parentheses(o,c-1,ans,op);
        return;
    }

    if(op[op.size()-1]==')'){
        parentheses(o-1,c,ans,op+'(');
        if(op.size()%2==1){
            parentheses(o,c-1,ans,op+')');
        }
        return;
    }

    parentheses(o-1,c,ans,op+'(');
    parentheses(o,c-1,ans,op+')');

    return;

}

void otherVersion(int o,int c,vector<string>&ans,string op=""){

    if(o==0 && c==0){
        ans.push_back(op);
        return;
    }

    if(o!=0){
        string op1 = op;
        op1.push_back('(');
        otherVersion(o-1,c,ans,op1);
        //return;
    }

    if(c>o){
        string op2 = op;
        op2.push_back(')');
        otherVersion(o,c-1,ans,op2);
        //return;
    }

    return;

}


int main(){

    cout<<"Enter Value:->";
    int n;cin>>n;

    vector<string> ans;

    //parentheses(n,n,ans);

    //for(auto i:ans){
      //  cout<<i<<"\n";
    //}
    //ans.clear();
    //cout<<"Other Answer...\n";
    otherVersion(n,n,ans);

    for(auto i:ans){
        cout<<i<<"\n";
    }

}
