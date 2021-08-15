#include<bits/stdc++.h>
using namespace std;

int LCString(string s1,string s2){

    int dp[s1.size()+1][s2.size()+1];
    int ret=0;
    // initialization
    for(int i=0;i<=s1.size();i++){
        for(int j=0;j<=s2.size();j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
        }
    }
    // choice diagram
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                ret=max(ret,dp[i][j]);
            }else{
                dp[i][j] = 0;
            }
        }
    }
    // printing dp table
    cout<<"\n";
    for(int i=0;i<=s1.size();i++){
        for(int j=0;j<=s2.size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return ret;

}

int main(){

    cout<<"Enter Two Strings:\n";
    string s1,s2;cin>>s1>>s2;

    cout<<"Longest Common Substring Length :->"<<LCString(s1,s2)<<"\n";

}
