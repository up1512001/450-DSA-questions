#include<bits/stdc++.h>
using namespace std;

void letterPermutation(string s,string op=""){

    if(s.size()==0){
        cout<<"String is :->"<<op<<"\n";
        return;
    }

    if(s[0]-'0'>=0 && s[0]-'0'<=9){
        letterPermutation(s.substr(1),op+s[0]);
        return;
    }
    string op1 = op;
    string op2 = op;

    op1.push_back(tolower(s[0]));
    op2.push_back(toupper(s[0]));

    letterPermutation(s.substr(1),op1);
    letterPermutation(s.substr(1),op2);

    return;

}


int main(){

    cout<<"Enter Alpha Numerical String :->";
    string s;cin>>s;

    letterPermutation(s);

}
