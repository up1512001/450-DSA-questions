#include<bits/stdc++.h>
using namespace std;

// Let middle element of stack is K then Kth index will be
// Kth index = stack.size()/2 + 1 -> this is 1 based indexing
// ex s = {1,3,7,5,6} then Kth will be 5/2 + 1 = 2+1 = 3 means 7 value
// ex s = {1,2,3,5,6,7} then Kth will be 6/2 + 1 = 3 + 1 = 4 means 3 value

void deleteMiddle(stack<int> &s,int k){
    if(k==0){
        cout<<"Stack Top:->"<<s.top()<<"\n";
        s.pop();
        return;
    }
    cout<<"Stack Top:->"<<s.top()<<"\n";
    int temp = s.top();
    s.pop();
    deleteMiddle(s,k-1);
    s.push(temp);
    return;
}

int main(){

    stack<int> s;
    cout<<"Enter Size Of Stack:";
    int n;cin>>n;
    cout<<"Enter Stack Element:\n";
    for(int i=0;i<n;i++){
        int x;cin>>x;
        s.push(x);
    }
    cout<<"After Deleting Middle Element of Stack:\n";
    deleteMiddle(s,s.size()/2);
    cout<<"Stack Size:->"<<s.size()<<"\n";
    for(;!s.empty();){
        cout<<s.top()<<" ";
        s.pop();
    }
}
