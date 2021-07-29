#include<bits/stdc++.h>
using namespace std;

void reverseString(string &s){

    if(s.size()==0){
        return;
    }
    char t = s[0];
    s.erase(s.begin()+0);
    reverseString(s);
    s.push_back(t);

    return;

}

int main(){

    cout<<"Enter String :->";
    string s;cin>>s;
    reverseString(s);
    cout<<"Reversed String using recursion is :->"<<s<<"\n";

}
