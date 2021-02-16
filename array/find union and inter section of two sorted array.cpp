#include<bits/stdc++.h>
#include"logic.cpp"
using namespace std;
map<ll,ll> mp;
// union of two sorted arrays O(n+m)
void u(ll a1[],ll a2[],ll n,ll m){
    ll i=0,j=0;
    while(i<n && j<m){
        if(a1[i] < a2[j]){
            cout<<a1[i++]<<" ";
        }else if(a1[i] > a2[j]){
            cout<<a2[j++]<<" ";
        }else if(a1[i] == a2[j]){
            cout<<a1[i++]<<" ";
            j++;
        }
    }
    if(i != n){
        while(i < n){
            cout<<a1[i++]<<" ";
        }
    }else if(j != m){
        while(j < m){
            cout<<a2[j++]<<" ";
        }
    }
}
// intersection of two sorted array O(n+m)
void i(ll a1[],ll a2[],ll n,ll m){
    ll i=0,j=0;
    while(i<n && j<m){
        if(a1[i] < a2[j]){
            i++;
        }else if(a1[i] > a2[j]){
            j++;
        }else if(a1[i] == a2[j]){
            cout<<a1[i]<<" ";
            i++;
            j++;
        }
    }
}
mp.clear();
// using map union of two sorted or unsorted array O(n+m)
void uni(ll a1[],ll a2[],ll n,ll m){
    for(ll i=0;i<n;i++){ mp.insert(a1[i],i);}
    for(ll i=0;i<m;i++){ mp.insert(a2[i],i);}
    for(auto itr=mp.begin();itr!=mp.end();itr++){
        cout<<itr->first<<" ";
    }
    cout<<endl;
}
int main(){
    tell;
    ll n;
    cin>>n;
    tell;
    ll m;
    cin>>m;
    ll arr1[n];
    enterarray;
    getarray(arr1,n);
    ll arr2[m];
    enterarray;
    getarray(arr2,m);
 /*   u(arr1,arr2,n,m);
    cout<<endl;
    i(arr1,arr2,n,m);
   */
   // map<int,int> ans;
    uni(arr1,arr2,n,m);


    cout<<endl;
}
