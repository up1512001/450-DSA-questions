#include<bits/stdc++.h>
using namespace std;

int static dp[1001][1001];

/*
P(N,K) = (N.(N-1).(N-2)....(N-K+1))
P(N,K) = (N!)/(N-K)!
*/
int permutationCofficient(int n,int k){

    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){
            // base condition
            if(j==0){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i-1][j]+(j*(dp[i-1][j-1]));
            }
            dp[i][j+1] =0;
        }
    }
    return dp[n][k];
}

int recursive(int n,int k){
    if(n==0 || k==0){
        return 1;
    }
    return (n*recursive(n-1,k-1));
}

int iterative(int n,int k){
    int ans=1;
    for(int i=0;i<k;i++){
        ans*=(n-i);
    }
    return ans;
}

int main(){

    memset(dp,-1,sizeof(dp));

    cout<<"Enter N value :->";
    int n;cin>>n;
    cout<<"Enter K value :->";
    int k;cin>>k;

    cout<<"permutation coefficient is :->"<<permutationCofficient(n,k)<<"\n";
    cout<<"permutation coefficient is :->"<<recursive(n,k)<<"\n";
    cout<<"permutation coefficient is :->"<<iterative(n,k)<<"\n";
}
