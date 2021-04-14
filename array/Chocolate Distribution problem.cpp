#include "logic.cpp"
// O(N Log N) time and O(1) space
ll sol(ll arr[],ll n,ll m){
    if(n==0 || m==0){
        return 0;
    }
    if(n < m){
        return -1;
    }
    sort(arr,arr+n);
    ll min_diff = INT_MAX;
    for(ll i=0;i+m-1<n;i++){
        ll diff = arr[i+m-1]-arr[i];
        if(min_diff > diff){
            min_diff=diff;
        }
    }
    return min_diff;
}
int main(){
    tell;
    ll n; cin>>n;
    ll arr[n];
    enterarray;
    getarray(arr,n);
    cout<<"Enter Number of Student:"<<endl;
    ll m; cin>>m;
    cout<<"Minimum difference between chocolate distribution:"<<sol(arr,n,m)<<endl;
}
