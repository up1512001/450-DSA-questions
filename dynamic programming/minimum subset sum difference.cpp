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

}
