#include<bits/stdc++.h>
using namespace std;

int minSubsetDifference(vector<int>&arr,int sum){

    int dp[arr.size()+1][sum+1];
    for(int i=0;i<arr.size()+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0)
                dp[i][j] = 0;
            if(j==0)
                dp[i][j] = 1;
        }
    }

    for(int i=1;i<arr.size()+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    vector<int> possibleSum;
    for(int i=0;i<(sum+1)/2;i++){
        if(dp[arr.size()][i]){
            possibleSum.push_back(i);
        }
    }
    int mn=INT_MAX;
    for(int i=0;i<possibleSum.size();i++){
        mn = min(mn,sum-2*possibleSum[i]);
    }

    return mn;

}

int main(){

    cout<<"Enter Size Of Array:->";
    int n;cin>>n;

    cout<<"Enter Array:\n";
    vector<int> arr(n,0);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }

    cout<<"Minimum Subset Sum Difference is :->"<<minSubsetDifference(arr,sum)<<"\n";

}
