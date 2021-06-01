#include<bits/stdc++.h>
using namespace std;


// this will take O(n1 + n2) time
// string::npos indicates until end of string
// static const size_t npos = -1;
bool possibalRotaion(string s1,string s2){
    if(s1.size() != s2.size()) return false;
    string temp = s1 + s1;
    return (temp.find(s2) != string::npos);

}

int main(){
    cout<<"Enter String 1:\n";
    string s1;cin>>s1;
    cout<<"Enter String 2:\n";
    string s2;cin>>s2;

    cout<<"Given s2 is rotation of s1 ?"<<possibalRotaion(s1,s2)<<"\n";

}
