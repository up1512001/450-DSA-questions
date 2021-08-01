#include<bits/stdc++.h>
using namespace std;

void nBitsBinary(int n,int o=0,int z=0,string op=""){

    if(n==0){
        cout<<"Your String is :->"<<op<<"\n";
        return;
    }

    if(o==z){
        nBitsBinary(n-1,o+1,z,op+'1');
        return;
    }
    if(o>z){
        nBitsBinary(n-1,o+1,z,op+'1');
        nBitsBinary(n-1,o,z+1,op+'0');
        return;
    }
    return;
}

int main(){

    cout<<"Enter Number :->";
    int n;cin>>n;

    nBitsBinary(n);

}
