#include<bits/stdc++.h>
using namespace std;

void helper(stack<int> &s,int temp){
    if(s.empty()){
        s.push(temp);
        cout<<"Stack Top:->"<<s.top()<<"\n";
        return;
    }
    int val=s.top();
    s.pop();
    helper(s,temp);
    s.push(val);
    cout<<"Stack Top:->"<<s.top()<<"\n";
    return;
}

void stackReverse(stack<int> &s){
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    stackReverse(s);
    helper(s,temp);
    return;
}

int main(){

    stack<int> s;
    cout<<"Enter Stack Size:";
    int n;cin>>n;
    cout<<"Enter Stack:\n";
    for(int i=0;i<n;i++){
        int x;cin>>x;
        s.push(x);
    }

    stackReverse(s);
    cout<<"Reversed Stack:\n";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
