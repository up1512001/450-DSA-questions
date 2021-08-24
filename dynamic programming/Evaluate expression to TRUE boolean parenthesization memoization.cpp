#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> mp;

int evaluateExpression(string &s,int i,int j,bool isTrue=true){

    if(i>j){
        return 0;
    }
    if(i==j){
        if(isTrue){
            return s[i]=='T';
        }else{
            return s[i]=='F';
        }
    }

    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));

    if(mp.find(temp)!=mp.end()){
        return mp[temp];
    }

    int ans=0;
    for(int k=i+1;k<j;k+=2){
        int lT = evaluateExpression(s,i,k-1,true);
        int lF = evaluateExpression(s,i,k-1,false);
        int rT = evaluateExpression(s,k+1,j,true);
        int rF = evaluateExpression(s,k+1,j,false);

        if(s[k]=='&'){
            if(isTrue){
                ans+= (lT*rT);
            }else{
                ans+=(lT*rF + lF*rT + lF*rF);
            }
        }else if(s[k]=='^'){
            if(isTrue){
                ans+=(lT*rF + lF*rT);
            }else{
                ans+=(lT*rT + lF*rF);
            }
        }else if(s[k]=='|'){
            if(isTrue){
                ans+=(lT*rT + lT*rF + lF*rT);
            }else{
                ans+= (lF*rF);
            }
        }
    }
    mp[temp] = ans;
    return mp[temp];

}

int main(){

    mp.clear();

    cout<<"Enter Boolean String :->";
    string s;cin>>s;

    cout<<"total possible way to evaluate expression to true are :->"<<evaluateExpression(s,0,s.size()-1)<<"\n";

}


