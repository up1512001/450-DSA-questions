#include<bits/stdc++.h>
using namespace std;

void uniqueSubsets(string s,string op,set<string> &st){

    if(s.size()==0){
        st.insert(op);
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(s[0]);
    s.erase(s.begin()+0);

    uniqueSubsets(s,op1,st);
    uniqueSubsets(s,op2,st);

    return;

}


int main(){

    cout<<"Enter String :->";
    string s;cin>>s;
    set<string> st;
    string op = "";

    uniqueSubsets(s,op,st);

    for(auto &it : st){
        cout<<it<<"\n";
    }

}
