#include<bits/stdc++.h>
using namespace std;

bool scrambled(string s1,string s2){

    if(s1.compare(s2)==0){
        return true;
    }
    if(s1.size()<=1){
        return false;
    }
    int n=s1.size();
    /*if(n==0){
        return true;
    }*/
    bool flag=false;
    for(int i=1;i<n;i++){
        if(scrambled(s1.substr(0,i),s2.substr(0,i))&&scrambled(s1.substr(i,n-i),s2.substr(i,n-i))){
            flag = true;
            break;

        }
        if(scrambled(s1.substr(0,i),s2.substr(n-i,i))&&scrambled(s1.substr(i,n-i),s2.substr(0,n-i))){
            flag = true;
            break;
        }
    }
    return flag;

}

int main(){

    cout<<"Enter Two Strings:\n";
    string s1,s2;
    cin>>s1>>s2;

    if(s1.size()!=s2.size()){
        cout<<"given strings are scrambled ? :->0\n";
    }

    cout<<"given strings are scrambled ? :->"<<scrambled(s1,s2)<<"\n";

}
