#include<bits/stdc++.h>
using namespace std;

int LPS(string s1,string s2){

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

    return dp[s1.size()][s2.size()];
}

int main(){

    cout<<"Enter String:->";
    string s;cin>>s;
    string t=s;
    reverse(s.begin(),s.end());
    cout<<"Longest Palindromic Sequence length is :->"<<LPS(t,s);

}
