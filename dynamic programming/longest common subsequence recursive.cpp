#include<bits/stdc++.h>
using namespace std;

int LCS(string s1,string s2,int n,int m){

    if(n==0 || m==0)
        return 0;
    if(s1[n-1]==s2[m-1]){
        return 1+LCS(s1,s2,n-1,m-1);
    }else{
        return max(LCS(s1,s2,n,m-1),LCS(s1,s2,n-1,m));
    }
    return -1;

}

int main(){

    cout<<"Enter Two Strings:\n";
    string s1,s2;cin>>s1>>s2;

    cout<<"Longest Common Subsequence length is :-> "<<LCS(s1,s2,s1.size(),s2.size())<<"\n";

}
