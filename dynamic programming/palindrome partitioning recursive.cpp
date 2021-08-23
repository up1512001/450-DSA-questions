#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s,int i,int j){

    while(i<=j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;

}

int minPalindromePartition(string &s,int i,int j){
    // base case
    if(i>=j){
        return 0;
    }
    if(isPalindrome(s,i,j)){
        return 0;
    }

    int mn = INT_MAX;
    // k loop iteration
    for(int k=i;k<j;k++){
        int tempans = 1 + minPalindromePartition(s,i,k) + minPalindromePartition(s,k+1,j);
        mn = min(mn,tempans);
    }

    return mn;

}

int main(){

    cout<<"Enter String :->";
    string s;cin>>s;

    cout<<"minimum number of partition to make each partition palindrome are :->"<<minPalindromePartition(s,0,s.size()-1);
}
