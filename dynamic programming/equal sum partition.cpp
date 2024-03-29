#include<bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int>&arr,int t){

    vector<vector<int>> dp(arr.size()+1,vector<int>(t+1));
    for(int i=0;i<arr.size()+1;i++){
        for(int j=0;j<t+1;j++){
            if(i==0)
                dp[i][j] = false;
            if(j==0)
                dp[i][j] = true;
        }
    }

    for(int i=1;i<arr.size()+1;i++){
        for(int j=1;j<t+1;j++){
            if(arr[i-1]<=j){
                dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[arr.size()][t];
}

bool equalSumPartition(vector<int> &arr){

    int sum=0;
    for(int i=0;i<arr.size();i++)
        sum+=arr[i];
    if(sum%2!=0) return false;
    else
        return subsetSum(arr,sum/2);

}

int main(){

    cout<<"Enter Size of Array :->";
    int n;cin>>n;
    vector<int> arr(n,0);
    cout<<"Enter Array :\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Equal Sum Partition Is Possible ? :->> "<<equalSumPartition(arr)<<"\n";

}
