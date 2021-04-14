
#include "logic.cpp"
#define ll int
ll maxProfit(ll price[],ll n){
    ll* profit = new int[n];
    for(ll i=0;i<n;i++){
        profit[i]=0;
    }
    ll max_profit=price[n-1];
    for(ll i=n-2;i>=0;i--){
        if(max_profit < price[i]){
            max_profit=price[i];
        }
        profit[i]=max(max_profit-price[i],profit[i+1]);
    }
    ll min_profit=price[0];
    for(ll i=1;i<n;i++){
        if(min_profit > price[i]){
            min_profit=price[i];
        }
        profit[i]=max(profit[i-1],profit[i]+(price[i]-min_profit));
    }
    ll ret = profit[n-1];
    delete[] profit;
    return ret;
}

// O(N) time
ll sol(ll arr[],ll n){
    ll profit = 0;
    for(ll i=1;i<n;i++){
        ll sub=arr[i]-arr[i-1];
        if(sub>0){
            profit+=sub;
        }
    }
    return profit;
}
int main(){
    tell;
    ll n;cin>>n;
    ll arr[n];
    enterarray;
    getarray(arr,n);
    //cout<<"Max Profit by atmost two sell is :"<<maxProfit(arr,n)<<endl;
    cout<<"Max Profit by atmost two sell is :"<<sol(arr,n)<<endl;
}
