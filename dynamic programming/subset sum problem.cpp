#include<bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int> arr,int t){

    vector<vector<int>> dp(arr.size()+1,vector<int>(t+1));
    for(int i=0;i<arr.size()+1;i++){
        for(int j=0;j<t+1;j++){
            if(i==0)
                dp[i][j] = false;
            if(j==0)
                dp[i][j]= true;
        }
    }

    for(int i=1;i<arr.size()+1;i++){
        for(int j=1;j<t+1;j++){
            if(arr[i-1] <= j){
                dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[arr.size()][t];
}

int main(){

    cout<<"Enter Array Size:->";
    int n;cin>>n;
    cout<<"Enter Array:\n";
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter Target Sum :->";
    int t;cin>>t;


    cout<<"Sum is Possible ? :-> "<<subsetSum(arr,t);

}
