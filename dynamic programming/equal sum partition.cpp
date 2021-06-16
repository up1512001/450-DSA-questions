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

bool equalSumPartition(v<int>&arr){
    int sum = 0;
    for(int i=0;i<arr.size();i++)
        sum+=arr[i];
    if(sum %2 != 0) return false;
    else{
        sum = sum/2;
        v<v<bool>> dp(arr.size()+1,v<bool>(sum+1,false));
        for(int i=0;i<dp.size();i++)
            dp[i][0] = true;
        for(int i=1;i<dp[0].size();i++)
            dp[0][i] = false;
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                if(arr[i-1] <= j){
                    dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        print(dp);
        return dp[dp.size()-1][dp[0].size()-1];
    }
    return false;
}

int main(){
    cout<<"Enter Array Size:\n";
    int n;cin>>n;
    cout<<"Enter Array :\n";
    v<int> arr(n,0);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Giver array Can be partition in TWO ? :-> "<<equalSumPartition(arr);
}
