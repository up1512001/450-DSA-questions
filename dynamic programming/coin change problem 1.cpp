#include<bits/stdc++.h>
using namespace std;

int maximumWaysCoin(vector<int>&coin,int sum){

    int dp[coin.size()+1][sum+1];

    // initialization
    for(int i=0;i<=coin.size();i++){
        for(int j=0;j<=sum;j++){
            if(i==0)
                dp[i][j] = 0;
            if(j==0)
                dp[i][j] = 1;
        }
    }

    // logic part
    for(int i=1;i<=coin.size();i++){
        for(int j=1;j<=sum;j++){
            if(coin[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i][j-coin[i-1]];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[coin.size()][sum];

}

int main(){

    cout<<"Enter Size of Coin array:->";
    int n;cin>>n;
    vector<int> coin(n,0);
    cout<<"Enter Coin Array:\n";
    for(int i=0;i<n;i++)
        cin>>coin[i];

    cout<<"Enter Target Sum Value:->";
    int sum;cin>>sum;

    cout<<"Maximum ways to get target sum are :-> "<<maximumWaysCoin(coin,sum)<<"\n";

}
