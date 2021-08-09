#include<bits/stdc++.h>
using namespace std;

int rodCutting(vector<int>&length,vector<int>&price,int rod){

    int dp[length.size()+1][rod+1];
    for(int i=0;i<=length.size();i++){
        for(int j=0;j<=rod;j++){
            if(i==0||j==0)
                dp[i][j]=0;
        }
    }

    for(int i=1;i<=length.size();i++){
        for(int j=1;j<=rod;j++){
            if(length[i-1]<=j){
                dp[i][j] = max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[length.size()][rod];
}


int main(){

    cout<<"Enter Size of Rod:->";
    int rod;cin>>rod;

    cout<<"Enter length array size:->";
    int n;cin>>n;
    vector<int>length(n,0);
    cout<<"Enter Length array:\n";
    for(int i=0;i<n;i++)
        cin>>length[i];
    cout<<"Enter Price Array:\n";
    vector<int>price(n,0);
    for(int i=0;i<n;i++)
        cin>>price[i];

    cout<<"Maximum profit after cutting rod is "<<rodCutting(length,price,rod)<<"\n";

}
