#include<bits/stdc++.h>
using namespace std;

string SCSPrint(string s1,string s2){

    // scs = s1.size() + s2.size() - lcs
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
    string s="";
    int i=s1.size(),j=s2.size();

    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            s.push_back(s1[i-1]);
            i--;
            j--;
        }else{
            if(dp[i-1][j] > dp[i][j-1]){
                s.push_back(s1[i-1]);
                i--;
            }else{
                s.push_back(s2[j-1]);
                j--;
            }
        }
    }
    while(i>0){
        s.push_back(s1[i-1]);
        i--;
    }
    while(j>0){
        s.push_back(s2[j-1]);
        j--;
    }

    reverse(s.begin(),s.end());
    return s;

}

int main(){

    cout<<"Enter Two Strings:\n";
    string s1,s2;
    cin>>s1>>s2;

    cout<<"Shortest Common Super Sequence is :->"<<SCSPrint(s1,s2)<<"\n";

}
