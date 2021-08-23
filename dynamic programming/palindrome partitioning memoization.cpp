#include<bits/stdc++.h>
using namespace std;

int static dp[1001][1001];

bool isPalindrome(string &s,int i,int j){

    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;

}

int minPalindromePartition(string &s,int i,int j){

    if(i>=j){
        return 0;
    }
    if(isPalindrome(s,i,j)){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int mn=INT_MAX;
    for(int k=i;k<j;k++){

        int tempans = 1+minPalindromePartition(s,i,k)+minPalindromePartition(s,k+1,j);
        mn = min(mn,tempans);
    }
    dp[i][j] = mn;
    return dp[i][j];

}

int main(){

    memset(dp,-1,sizeof(dp));

    cout<<"Enter String :->";
    string s;cin>>s;

    cout<<"minimum partition to make palindrome are :->"<<minPalindromePartition(s,0,s.size()-1)<<"\n";

}
