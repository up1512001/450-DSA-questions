#include<bits/stdc++.h>
using namespace std;
#include"logic.cpp"
void leftrotate(ll arr[],ll n){
    ll f=arr[0];
    for(ll i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=f;
}
void rightrotate(ll arr[],ll n){
    ll l=arr[n-1];
    for(ll i=n-1;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=l;
}
int main(){
    tell;
    ll n;
    cin>>n;
    enterarray;
    ll arr[n];
    getarray(arr,n);
    leftrotate(arr,n);
    print(arr);
    cout<<"\n";
    rightrotate(arr,n);
    print(arr);

}
