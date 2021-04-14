#include "logic.cpp"
struct eleCount{
    public:
    ll e;
    ll c;
};

// O(N * K) time and O (K-1) space
vector<ll> sol(ll arr[],ll n,ll k){
    if(k<2)return {arr[0]};
    struct eleCount temp[k-1];
    for(ll i=0;i<k-1;i++){
        temp[i].c = 0;
    }
    for(ll i=0;i<n;i++){
        ll j;
        for(j=0;j<k-1;j++){
            if(temp[j].e == arr[i]){
                temp[j].c+=1;
                break;
            }
        }
        if(j == k-1){
            ll l;
            for(l=0;l<k-1;l++){
                if(temp[l].c == 0){
                    temp[l].c = 1;
                    temp[l].e = arr[i];
                    break;
                }
            }
            if(l == k-1){
                for(l=0;l<k;l++){
                    temp[l].c-=1;
                }
            }
        }
    }
    vector<ll> a;
    for(ll i=0;i<k-1;i++){
        ll ac=0;
        for(ll j=0;j<n;j++){
            if(arr[j]==temp[i].e){
                ac++;
            }
        }
        if(ac > (n/k)){
            a.pb(temp[i].e);
        }
    }
    //for(ll i=0;i<a.size();i++) cout<<a[i]<<" ";
    return a;
}

// O(N) time and O(N) space
vector<ll> sol2(ll arr[],ll n,ll k){
    unordered_map<ll,ll> m;
    vector<ll> a;
    for(ll i=0;i<n;i++){
        m[arr[i]]++;
    }
    for(auto i : m){
        if(i.second > (n/k)){
            a.pb(i.first);
        }
    }
    return a;
}

int main(){
    tell;
    ll n;cin>>n;
    cout<<"Enter K value:"<<endl;
    ll k;cin>>k;
    ll arr[n];
    enterarray;
    getarray(arr,n);
    vector<ll> ans;
    ans=sol2(arr,n,k);
    for(ll i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;

}
