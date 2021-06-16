#include<bits/stdc++.h>
using namespace std;
#define v vector
#define pb push_back

// printing
void print(v<v<bool>> &dp){
    cout<<"\nPrinting DP Table:\n";
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[i].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"End Of Table:\n";
}

bool targetsumDP(v<int> &arr,int t){
    v<v<bool>> dp(arr.size()+1,v<bool>(t+1,false));
    for(int i=0;i<dp.size();i++){
        dp[i][0] = true;
    }
    for(int i=1;i<dp[0].size();i++){
        dp[0][i] = false;
    }
    print(dp);
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[0].size();j++){
            if(arr[i-1] <= j){
                dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }
            else if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    print(dp);
    return dp[arr.size()][t];
}

int main(){
    cout<<"Enter Array Size:->";
    int n;cin>>n;
    cout<<"\nEnter Array:\n";
    v<int> arr(n,0);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter Target Value :->";
    int t;cin>>t;
    cout<<"Target Sum Present Or Not ? :-> "<<targetsumDP(arr,t);
}
