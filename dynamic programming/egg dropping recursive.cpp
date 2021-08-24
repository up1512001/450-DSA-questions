#include<bits/stdc++.h>
using namespace std;

int eggDrop(int e,int f){

    // base case
    if(f==0 || f==1)
        return f;
    if(e==1)
        return f;

    int mn=INT_MAX;

    // looping over k
    for(int k=1;k<=f;k++){
        int tempans = 1+max(eggDrop(e-1,k-1),eggDrop(e,f-k));
        mn = min(mn,tempans);
    }
    return mn;
}

int main(){

    cout<<"Enter number of egg's:->";
    int e;cin>>e;
    cout<<"Enter total floor:->";
    int f;cin>>f;

    cout<<"minimum number of attempt in worst case are :->"<<eggDrop(e,f)<<"\n";

}
