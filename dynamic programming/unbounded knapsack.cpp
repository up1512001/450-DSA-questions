#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(vector<int>&wt,vector<int>&val,int cap){

    int dp[wt.size()+1][cap+1];
    for(int i=0;i<=wt.size();i++){
        for(int j=0;j<=cap;j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
        }
    }

    for(int i=1;i<=wt.size();i++){
        for(int j=1;j<=cap;j++){
            if(wt[i-1]<=j){
                dp[i][j] = max(dp[i][j-wt[i-1]]+val[i-1],dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[wt.size()][cap];
}

int main(){

    cout<<"Enter Size Of Array:->";
    int n;cin>>n;
    cout<<"Enter Weight Array:\n";
    vector<int> wt(n,0);
    for(int i=0;i<n;i++)
        cin>>wt[i];
    cout<<"Enter Value Array:\n";
    vector<int>val(n,0);
    for(int i=0;i<n;i++)
        cin>>val[i];
    cout<<"Enter Size Of Knapsack:->";
    int cap;cin>>cap;

    cout<<"Maximum Profit Will Be :->"<<unboundedKnapsack(wt,val,cap)<<"\n";

}
