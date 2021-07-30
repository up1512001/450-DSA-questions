#include<bits/stdc++.h>
using namespace std;

void printSubstring(string s){

    for(int i=0;i<s.size();i++){
        for(int len = 1;len<=s.size()-i;len++){
            cout<<"Substring is :->"<<s.substr(i,len)<<"\n";
        }
    }

}

void recursivePrint(string s,string op=""){

    if(s.size()==0){
        cout<<"Substring is :->"<<op<<"\n";
        return;
    }
    if(!op.empty()){
        recursivePrint("",op);
    }else{
        recursivePrint(s.substr(1),op);
    }
    recursivePrint(s.substr(1),op+s[0]);

    return ;
}


int main(){

    cout<<"Enter String :->";
    string s;cin>>s;

    //printSubstring(s);
    recursivePrint(s);
}
