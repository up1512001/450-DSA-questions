#include<bits/stdc++.h>
using namespace std;

int minInsertion(string s){

    string t;
    int dp[s.size()+1][t.size()+1];

    reverse(begin(t),end(t));

    for(int i=0;i<=s.size();i++)
        for(int j=0;j<=t.size();j++)
            if(i==0 || j==0)
                dp[i][j] = 0;

    for(int i=1;i<=s.size();i++){
        for(int j=1;j<=t.size();j++){
            if(s[i-1]==t[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<
    return s.size() - dp[s.size()][t.size()];

}

int main(){

    cout<<"Enter String :->";
    string s;cin>>s;

    cout<<"minimum number of insertions to make given string palindrome are :->"<<minInsertion(s)<<"\n";

}
