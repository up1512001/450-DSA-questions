#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void found(vector<vector<ll> >a,ll r,ll c,ll f){
    for(ll i=0;i<r;i++){
        for(ll j=0;j<c;j++){
            if(a[i][j]==f){
                cout<<"Element Found at ROW NO:"<<i+1<<" and COLUMN NO:"<<j+1<<endl;
                return;
            }
        }
    }
    cout<<"Element Not Found..."<<endl;
    return;
}

int main(){
    cout<<"Enter rows and columns:"<<endl;
    ll r,c;cin>>r>>c;
    vector<vector<ll> > arr;
    cout<<"Enter Matrix:"<<endl;
    for(ll i=0;i<r;i++){
        vector<ll> a;
        for(ll j=0;j<c;j++){
            ll x;
            cin>>x;
            a.push_back(x);
        }
        arr.push_back(a);
        a.clear();
    }
    cout<<"Enter Element to Find in Matrix:"<<endl;
    ll f;cin>>f;

    found(arr,r,c,f);
}

