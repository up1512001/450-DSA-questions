#include"logic.cpp"

// basic approach O(N) and O(1) space complexity
void sol(){
    vector<ll> a;
    tell;
    ll n;
    cin>>n;
    enterarray;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        a.pb(x);
    }
    ll ind=-1;
    for(ll i=a.size()-1;i>0;i--){
        if(a[i]>a[i-1]){
            ind=i;
            break;
        }
    }
    if(ind == -1){
        reverse(a.begin(),a.end());
    }else{
        ll prev=ind;
        for(ll i=ind+1;i<a.size();i++){
            if(a[i]>a[ind-1] && a[i]<=a[prev]){
                prev=i;
            }
        }
        swap(a[ind-1],a[prev]);
        reverse(a.begin()+ind,a.end());
    }

    // prenting
    cout<<"Next Permutation:"<<endl;
    for(ll i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    sol();
}
