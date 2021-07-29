#include<bits/stdc++.h>
using namespace std;

void subsets(string ip,string op){

    if(ip.size()==0){
        cout<<"Subsets Are:->"<<op<<"\n";
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);

    subsets(ip,op1);
    subsets(ip,op2);

    return;
}


int main(){

    cout<<"Enter String:->";
    string ip;cin>>ip;
    string op="";

    subsets(ip,op);


}
