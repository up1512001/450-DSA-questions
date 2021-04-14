#include"logic.cpp"

vector<ll> sol(ll a1[],ll a2[],ll a3[],ll n,ll m,ll p){
    vector<ll> ans;
    ll i=0,j=0,k=0;
    while(i<n && j<m && k<p){
        if(a1[i]==a2[j] && a2[j]==a3[k]){
            ans.pb(a1[i]);
            i++;j++;k++;
        }
        else if(a1[i]<a2[j]){
            i++;
        }
        else if(a2[j]<a3[k]){
            j++;
        }
        else{
            k++;
        }
    }
     ans.erase(unique(ans.begin(),ans.end()),ans.end());
     return ans;
}
int main(){
    tell;
    ll n;
    cin>>n;
    ll arr1[n];
    enterarray;
    getarray(arr1,n);
    tell;
    ll m;
    cin>>m;
    ll arr2[m];
    enterarray;
    getarray(arr2,m);
    tell;
    ll k; cin>>k;
    ll arr3[k];
    enterarray;
    getarray(arr3,k);
    vector<ll>ans;
    ans=sol(arr1,arr2,arr3,n,m,k);
    cout<<"common Elements:";
    print(ans,ans.size());
}
