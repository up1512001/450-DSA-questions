#include<bits/stdc++.h>
using namespace std;

long long catalan(int n){

    if(n<=1){
        return 1;
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=(catalan(i)*catalan(n-i-1));
    }
    return ans;
}

long long catalanDP(int n){

    long long dp[n+1];
    dp[0] = dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i]=0;
        for(int j=0;j<i;j++){
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}

long long catalanIterative(int n){

    // formula C(n) = (2*n)C(n) * (1/(n+1))

    long long ans=1;
    int k=n;
    n*=2;

    if(k>n-k){
        k=n-k;
    }
    for(int i=0;i<k;i++){
        ans*=(n-i);
        ans/=(i+1);
    }
    return ans/((n/2)+1);
}

int main(){

    // basic catalan number calculation
    for(int i=0;i<10;i++){
        cout<<catalan(i)<<" ";
    }
    cout<<"\n";


    cout<<"Catalan number (DP) :->"<<catalanDP(19)<<"\n";

    cout<<"Catalan number (Iterative) :->"<<catalanIterative(19)<<"\n";
}
