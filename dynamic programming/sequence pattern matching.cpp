#include<bits/stdc++.h>
using namespace std;

bool isSubsequence(string s1,string s2){

    int dp[s1.size()+1][s2.size()+1];

    for(int i=0;i<=s1.size();i++){
        for(int j=0;j<=s2.size();j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
        }
    }

    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    //cout<<s1.size()<<" "<<dp[s1.size()][s2.size()]<<"\n";
    return s1.size()==dp[s1.size()][s2.size()]?1:0;

}

int main(){

    cout<<"Enter Two Strings:\n";
    string s1,s2;
    cin>>s1>>s2;

    cout<<"s1 is subsequence is s2 ? :-->"<<isSubsequence(s1,s2)<<"\n";

}
