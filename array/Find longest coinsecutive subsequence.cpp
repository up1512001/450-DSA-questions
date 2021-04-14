#include "logic.cpp"

// O(N Log N) time and O(N) space
ll sequenceLen(ll arr[],ll n){
    ll ans=0,cnt=0;
    vector<ll> a;
    sort(arr,arr+n);
    a.pb(arr[0]);
    for(ll i=1;i<n;i++){
        if(arr[i]!=arr[i-1]){
            a.pb(arr[i]);
        }
    }
    for(ll i=0;i<a.size();i++){
        if(i>0 && a[i] == a[i-1]+1){
            cnt++;
        }else{
            cnt=1;
        }
        ans=max(ans,cnt);
    }
    return ans;
}

// O(N) time and O(N) space
ll ans(ll arr[],ll n){
    unordered_set<ll> a;
    for(ll i=0;i<n;i++){
        a.insert(arr[i]);
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(a.find(arr[i]-1) == a.end()){
            ll j=arr[i];
            while(a.find(j) != a.end()){
                j++;
            }
            ans = max(ans,j-arr[i]);
        }
    }
    return ans;
}

int main(){
    tell;
    ll n; cin>>n;
    ll arr[n];
    enterarray;
    getarray(arr,n);

    cout<<"Maximum Continuous Sequence Length:"<<sequenceLen(arr,n)<<endl;
    cout<<"Maximum Continuous Sequence Length:"<<ans(arr,n)<<endl;
}
