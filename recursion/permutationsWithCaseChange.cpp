#include<bits/stdc++.h>
using namespace std;

void casePermutations(string s,string op=""){

    if(s.size()==0){
        cout<<"String :->"<<op<<"\n";
        return;
    }
    string op1 = op;
    op1+=toupper(s[0]);

    casePermutations(s.substr(1),op+s[0]);
    casePermutations(s.substr(1),op1);

    return;

}

int main(){

    cout<<"Enter String :->";
    string s;cin>>s;

    casePermutations(s);

}
