#include "logic.cpp"
using namespace std;

int minimizeHeight(ll arr[],ll n,ll k){
    if(n==1) return 0;
    sort(arr,arr+n);
    ll small=arr[0]+k;
    ll big=arr[n-1]-k;
    ll ans=arr[n-1]-arr[0];
    if(big<small) swap(big,small);
    for(ll i=1;i<n-1;i++){
        ll add=arr[i]+k;
        ll sub=arr[i]-k;
        if(sub>= small || big>= add) continue;
        if(big-sub<= add-small) small=sub;
        else big=add;

    }
    return min(ans,big-small);
}

int main(){
    tell;
    ll n;
    cin>>n;
    ll arr[n];
    cout<<"Enter K value:"<<endl;
    ll k; cin>>k;
    enterarray;
    getarray(arr,n);
    cout<<"Minimized Difference of Heights:"<<minimizeHeight(arr,n,k)<<endl;
}
