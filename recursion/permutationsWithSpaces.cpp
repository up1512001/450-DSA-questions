#include<bits/stdc++.h>
using namespace std;

void permutationSpaces(string s,string op=""){

    if(s.size()==0){
        cout<<"Your String is :->"<<op<<"\n";
        return;
    }
    if(op.size()==0){
        permutationSpaces(s.substr(1),op+s[0]);
        return;
    }

    permutationSpaces(s.substr(1),op+"_"+s[0]);
    permutationSpaces(s.substr(1),op+s[0]);

    return;

}

int main(){

    cout<<"Enter String :->";
    string s;cin>>s;

    permutationSpaces(s);

}
