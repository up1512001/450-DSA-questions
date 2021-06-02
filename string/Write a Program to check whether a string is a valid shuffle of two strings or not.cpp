#include<bits/stdc++.h>
using namespace std;

// this will take O(N) time and O(1) space
bool validShuffle(string s1,string s2,string r){
    if(r.size()!=(s1.size()+s2.size())) return false;
    int i=0,j=0,k=0;
    while(k<r.size()){
        if(s1[i]==r[k]){
            i++;
        }else if(s2[j]==r[k]){
            j++;
        }else{
            return false;
        }
        k++;
    }
    if(i!=s1.size() || j!=s2.size()) return false;
    return true;
}

int main(){
    cout<<"Enter two strings:\n";
    string s1,s2;cin>>s1>>s2;
    cout<<"Enter Result String:\n";
    string res;cin>>res;
    cout<<"Enter Result String is Valid Shuffle ?"<<validShuffle(s1,s2,res)<<"\n";
}
