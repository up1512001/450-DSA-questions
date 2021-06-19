#include<bits/stdc++.h>
using namespace std;
#define v vector

void print(v<v<int>>&dp){
    cout<<"Printing DP Table:\n";
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"End of Table:\n";
}

int countSubset(v<int> &arr,int t){
    v<v<int>> dp(arr.size()+1,v<int>(t+1,0));
    // initialization
    for(int i=0;i<dp.size();i++)
        dp[i][0] = 1;
    for(int i=1;i<dp[0].size();i++)
        dp[0][i] = 0;
    // calculation
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[0].size();j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    print(dp);
    return dp[dp.size()-1][dp[0].size()-1];
}

int main(){
    cout<<"Enter size of Array:\n";
    int n;cin>>n;
    v<int> arr(n,0);
    cout<<"Enter Array :\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter finding sum:\n";
    int t;cin>>t;
    cout<<"Total possible subsets are :->"<<countSubset(arr,t)<<"\n";
}
