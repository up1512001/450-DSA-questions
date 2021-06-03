#include<bits/stdc++.h>
using namespace std;

// brute force time O(N ^ 3) and space will be O(1)

int bruteForce(string s){
    int maxlen = 1,start = 0;
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            int flag = 1;
            for(int k = 0;k<(j-i+1)/2;k++){
                if(s[i+k] != s[j-k]){
                    flag=0;
                }
            }
            if(flag && (j-i+1)>maxlen){
                start=i;
                maxlen = j-i+1;
            }
        }
    }
    cout<<"Longest Palindrome substring :->";
    for(int i=start;i<start+maxlen;i++)
        cout<<s[i];
    cout<<"\n";

    return maxlen;
}

// applying DP time will be O(N ^ 2) and space O(N ^ 2)
int basicDp(string s){
    int maxlen = 1;
    int start = 0;
    bool dp[s.size()][s.size()];
    memset(dp,0,sizeof(dp));
    // all sub string of length 1 are palindrome
    for(int i=0;i<s.size();i++){
        dp[i][i]=true;
    }
    // checking for length 2 palindrome
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            dp[i][i+1] = true;
            start = i;
            maxlen = 2;
        }
    }
    // now checking for length greater than 2
    for(int k=3;k<=s.size();k++){
        for(int i=0;i<s.size()-k+1;i++){
            int j = i+k-1;
            if(dp[i+1][j-1] && s[i]==s[j]){
                dp[i][j]=true;
                if(k>maxlen){
                    start = i;
                    maxlen = k;
                }
            }
        }
    }
    cout<<"Longest Palindrome substring :->";
    for(int i=start;i<start+maxlen;i++)
        cout<<s[i];
    cout<<"\n";

    return maxlen;
}

// optimized approach O(N ^ 2) and space will be O(1)
int optimized(string s){
    int maxlen = 1;
    int start = 0;
    int low,high;
    for(int i=1;i<s.size();i++){
        low = i-1;
        high = i;

        while(low >= 0 && high < s.size() && s[low] == s[high]){
            if(high-low+1 > maxlen){
                start=low;
                maxlen = high-low+1;
            }
            low--;
            high++;
        }

        low = i-1;
        high = i+1;
        while(low >= 0 && high< s.size() && s[low]==s[high]){
            if(high-low+1 > maxlen){
                start=low;
                maxlen = high-low+1;
            }
            low--;
            high++;
        }
    }
    cout<<"Longest Palindrome substring :->";
    for(int i=start;i<start+maxlen;i++)
        cout<<s[i];
    cout<<"\n";

    return maxlen;
}


int main(){
    cout <<" Enter String To get maximum length palindrome substring :\n";
    string s;cin>>s;
    //cout<<"Brute Force :"<<bruteForce(s)<<"\n";
    //cout<<"Basic DP approach :->"<<basicDp(s)<<"\n";
    cout<<"Optimized approach :->"<<optimized(s)<<"\n";
}
