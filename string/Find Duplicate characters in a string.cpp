#include<bits/stdc++.h>
using namespace std;

// time complexity will be O(N Log N) and Space will be O(N) for map
string duplicateUsingMap(string s){
    map<char,int> mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    string ret = "";
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second > 1) ret+=it->first;
    }
    return ret;
}

// by using unordered_map insertion time will be reduce from O(Log N) to O(1)
// so time complexity will be O(N) an Space complexity will be O(N)
string duplicateUsingUnorderedMap(string s){
    unordered_map<char,int> mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    string ret="";
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second > 1) ret+=it->first;
    }
    return ret;
}


int main(){
    cout<<"Enter String with duplicate elements:\n";
    string s;cin>>s;
    //string d = duplicateUsingMap(s);
    //cout<<"Duplicate Elements in string are :"<<d<<"\n";
    string d = duplicateUsingUnorderedMap(s);
    cout<<"Duplicate Elements in string are :"<<d<<"\n";
}
