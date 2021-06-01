#include<bits/stdc++.h>
using namespace std;
#define v vector

void reverseString(string &s){
    for(int i=0,j=s.size()-1;i<j;i++,j--){
        swap(s[i],s[j]);
    }
}

int main(){
    cout<<"Enter String:\n";
    string s;cin>>s;
    reverseString(s);
    cout<<"Reversed String :"<<s<<"\n";
}
