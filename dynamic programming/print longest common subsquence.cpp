#include<bits/stdc++.h>
using namespace std;

string LCS(string s1,string s2,int l1,int l2){

    int dp[l1+1][l2+1];
    // initialization
    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
        }
    }
    // choice diagram
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    // getting string
    string ret="";
    int i=l1,j=l2;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ret.push_back(s1[i-1]);
            i--;
            j--;
        }else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    cout<<dp[l1][l2]<<"\n";
    reverse(ret.begin(),ret.end());
    return ret;
}

int main(){

    cout<<"Enter Two Strings:\n";
    string s1,s2;
    cin>>s1>>s2;

    cout<<"Longest Common Subsequence is :->"<<LCS(s1,s2,s1.size(),s2.size())<<"\n";


}
