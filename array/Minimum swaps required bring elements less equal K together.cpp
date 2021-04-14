#include "logic.cpp"
// O(N) time O(1) space
ll sol(ll arr[],ll n,ll k){
    ll less_k=0,big_k=0,min_swap=INT_MAX;
    for(ll i=0;i<n;i++){
        if(arr[i]<=k)less_k++;
    }
    for(ll i=0;i<less_k;i++){
        if(arr[i]>k)big_k++;
    }
    ll i=0,j=less_k-1;
    while(j<n){
        min_swap = min(min_swap,big_k);
        j++;
        if(arr[j]>k && j<n) big_k++;
        if(arr[i]>k) big_k--;
        i++;
    }
    return min_swap;
}
int main(){
    tell;
    ll n;cin>>n;
    ll arr[n];
    enterarray;
    getarray(arr,n);
    cout<<"Enter K value:";
    ll k;cin>>k;
    cout<<"Minimum swap Required:"<<sol(arr,n,k)<<endl;
}
