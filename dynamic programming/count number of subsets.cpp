#include<bits/stdc++.h>
using namespace std;

int countNumberOfSubset(vector<int>&arr,int sum){

    int dp[arr.size()+1][sum+1];
    for(int i=0;i<arr.size()+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i == 0)
                dp[i][j] = 0;
            if(j==0)
                dp[i][j] = 1;
        }
    }

    for(int i=1;i<arr.size()+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j-arr[i-1]]+dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[arr.size()][sum];

}

int main(){

    cout<<"Enter Size Of Array :->";
    int n;cin>>n;
    vector<int> arr(n,0);
    cout<<"Enter Array :\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter Sum Value :->";
    int sum;cin>>sum;
    cout<<"Number of Possible Subsets : "<<countNumberOfSubset(arr,sum)<<"\n";

}
