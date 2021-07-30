#include<bits/stdc++.h>
using namespace std;

void printSubstring(string s,string op){

    if(s.size()==0){
        cout<<"Substring is :->"<<op<<"\n";
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(s[0]);
    s.erase(s.begin()+0);

    printSubstring(s,op2);
    printSubstring(s,op1);

    return;

}

int main(){

    cout<<"Enter String :->";
    string s;cin>>s;
    string op="";

    printSubstring(s,op);

}
