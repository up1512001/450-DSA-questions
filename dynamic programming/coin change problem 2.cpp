#include<bits/stdc++.h>
using namespace std;

int minimumNumberOfCoin(vector<int>&coin,int sum){

    int dp[coin.size()+1][sum+1];

    // initialization
    for(int i=0;i<=coin.size();i++){
        for(int j=0;j<=sum;j++){
            if(i==0){
                dp[i][j] = INT_MAX-1;
            }else if(j==0){
                dp[i][j] = 0;
            }
        }
    }
    // second raw initialization
    for(int j=1;j<=sum;j++){
        if(j%coin[0]==0){
            dp[1][j] = j/coin[0];
        }
    }

    // main logic
    for(int i=2;i<=coin.size();i++){
        for(int j=1;j<=sum;j++){
            if(coin[i-1]<=j){
                dp[i][j] = min(1+dp[i][j-coin[i-1]],dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // return
    return dp[coin.size()][sum];

}

int main(){

    cout<<"Enter Size of Coin Array:->";
    int n;cin>>n;

    cout<<"Enter Coin Array:\n";
    vector<int> coin(n,0);
    for(int i=0;i<n;i++)
        cin>>coin[i];

    cout<<"Enter Required Sum:->";
    int sum;cin>>sum;

    cout<<"Minimum number of coin required to get given sum are :->"<<minimumNumberOfCoin(coin,sum)<<"\n";

}
