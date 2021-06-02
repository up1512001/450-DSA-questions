#include<bits/stdc++.h>
using namespace std;


// O(N^2) time and O(N) space (string temp of str.size())
string countAndSay(int n){
    if(n==1) return "1";
    else if(n==2) return "11";

    string str = "11";
    for(int i=3;i<=n;i++){
        str+='$';
        int len = str.size();
        int cnt = 1;
        string temp = "";
        for(int j=1;j<len;j++){
            if(str[j]!=str[j-1]){
                temp += cnt + '0';
                //cout<<"Temp->"<<temp<<"\n";
                temp += str[j-1];
                cnt = 1;
            }
            else cnt++;
        }
        str = temp;
    }
    return str;
}

int main(){
    cout<<"Enter Number:\n";
    int n;cin>>n;

    cout<<"Count And Say :"<<countAndSay(n)<<"\n";
}
