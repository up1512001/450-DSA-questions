#include<bits/stdc++.h>
using namespace std;
#define v vector
#define pb push_back
#define pii pair<int,int>
//#define ff first
//#define ss second

v<int> CommonUsingMap(v<v<int>> &arr){
    map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i][0]]++;
        for(int j=1;j<arr[0].size();j++){
            if(arr[i][j] != arr[i][j-1]){
                mp[arr[i][j]]++;
            }
        }
    }
    v<int> ans;
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second == arr.size()){
            ans.pb(it->first);
        }
    }
    if(ans.size()==0) return {-1};
    return ans;
}

int main(){
    cout<<"Enter Row and Column Size:\n";
    int r,c;cin>>r>>c;
    v<v<int>> arr;
    cout<<"Enter Matrix:\n";
    for(int i=0;i<r;i++){
        v<int> t;
        for(int j=0;j<c;j++){
            int x;cin>>x;
            t.pb(x);
        }
        arr.pb(t);
    }
    v<int> ans = CommonUsingMap(arr);
    cout<<"Ans Vector:\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
