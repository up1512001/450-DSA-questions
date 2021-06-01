#include<bits/stdc++.h>
using namespace std;

bool palindrome(string s){
    for(int i=0,j=s.size()-1;i<j;j--,i++){
        if(s[i]!=s[j]) return false;
    }
    return true;
}

int main(){
    cout<<"Enter String To Check Palindrome or Not:\n";
    string s;cin>>s;
    cout<<"String is Palindrome ?"<<palindrome(s)<<"\n";
}
