#include "logic.cpp"
// O(N^2) time and O(1) space
ll sol1(ll arr[],ll n,ll x){
    ll min_len=INT_MAX;
    ll sum=0;
    for(ll i=0;i<n;i++){
        sum=0;
        for(ll j=i;j<n;j++){
            sum+=arr[j];
            if(sum>x){
                min_len = min(min_len,j-i+1);
                break;
            }
        }
    }
    return min_len;
}
// O(N) time and O(1) space
ll sol2(ll arr[],ll n,ll x){
    ll i=0,j=0;
    ll min_len=INT_MAX;
    ll sum=0;
    while(i<=j && j<n){
        while(sum<x && j<n){
            sum+=arr[j++];
        }
        while(sum>x && i<j){
            min_len = min(min_len,j-i);
            sum-=arr[i];
            i++;
        }
    }
    return min_len;
}
int main(){
    tell;
    ll n; cin>>n;
    ll arr[n];
    enterarray;
    getarray(arr,n);
    cout<<"Enter Sum Value:"<<endl;
    ll x; cin>>x;
    cout<<""<<sol1(arr,n,x)<<endl;
}
