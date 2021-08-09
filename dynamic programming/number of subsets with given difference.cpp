#include<bits/stdc++.h>
using namespace std;

int subsetWithGivenDiff(vector<int>&arr,int diff){

    int sum=0;
    for(int i=0;i<arr.size();i++)
        sum+=arr[i];

    if((sum+diff)%2==1 || diff>sum || diff<-sum)return 0;
    cout<<"Array Sum :->"<<sum<<"\n";
    sum = (diff + sum)/2;
    cout<<"Needed Sum :->"<<sum<<"\n";
    int dp[arr.size()+1][sum+1];
    for(int i=0;i<=arr.size();i++){
        for(int j=0;j<=sum;j++){
            if(i==0)
                dp[i][j] = 0;
            if(j==0)
                dp[i][j] = 1;
        }
    }

    for(int i=1;i<=arr.size();i++){
        for(int j=sum;j>=0;j--){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[arr.size()][sum];

}

int main(){

    cout<<"Enter Array Size :->";
    int n;cin>>n;
    cout<<"Enter Array:\n";
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter Difference Value:->";
    int diff;cin>>diff;

    cout<<"Number of possible subsets are :->"<<subsetWithGivenDiff(arr,diff)<<"\n";

}
