#include<bits/stdc++.h>
using namespace std;


int grammar(int n,int k){

    // base condition
    if(n==1 && k==1)
        return 0;

    // induction
    int mid = pow(2,n-1)/2;

    if(k<=mid)
        return grammar(n-1,k);
    else
        return !grammar(n-1,k-mid);

}

int main(){

    cout<<"Enter N and K Value :";
    int n,k;cin>>n>>k;


    cout<<"Grammar at Nth row and Kth column is :->"<<grammar(n,k)<<"\n";
}
