#include<bits/stdc++.h>
using namespace std;

void ins(stack<int> &s,int temp){
    if(s.size()==0 || s.top() <= temp){
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    ins(s,temp);
    s.push(val);
    return;
}

void srt(stack<int>&s){

    if(s.size()==1){
        return;
    }
    int temp= s.top();
    s.pop();
    srt(s);
    ins(s,temp);
    return;
}

int main(){

    cout<<"Enter Size of Stack:";
    int n;cin>>n;
    stack<int> s;
    cout<<"Enter Stack:\n";
    for(int i=0;i<n;i++){
        int x;cin>>x;
        s.push(x);
    }
    srt(s);
    cout<<"Sorted Stack:\n";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
