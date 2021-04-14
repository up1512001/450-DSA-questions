#include"logic.cpp"
using namespace std;

vector<ll> mergetwosorted(ll a1[],ll a2[],ll n,ll m){
    vector<ll> ans;
    ll i=0,j=0;
    while(i<n && j<m){
        if(a1[i]<a2[j]){
            ans.pb(a1[i++]);
        }else if(a2[j]<a1[i]){
            ans.pb(a2[j++]);
        }else if(a1[i]==a2[j]){
            ans.pb(a1[i++]);
            j++;
        }
    }
    while(i<n){
        ans.pb(a1[i++]);
    }
    while(j<m){
        ans.pb(a2[j++]);
    }
    return ans;
}

// sort both array with out using extra space
ll c(ll n){
    if(n<=1)return 0;
    else return (n/2)+(n%2);
}
void sortboth(ll a1[],ll a2[],ll n,ll m){
    ll i,j,gap=n+m;
    for(ll gap=c(gap);gap>0;gap/=2){

        for(i=0;i+gap<n;i++){
            if(a1[i]>a1[i+gap]){
                swap(a1[i],a1[i+gap]);
            }
        }
        for(j=gap>n?gap-n:0;i<n && j<m;i++,j++){
            if(a1[i]>a2[j]){
                swap(a1[i],a2[j]);
            }
        }
        if(j<m){
            for(j=0;j+gap<m;j++){
                if(a2[j]>a2[j+gap]){
                    swap(a2[j],a2[j+gap]);
                }
            }
        }
    }
}

void merge(ll a1[],ll a2[],ll n,ll m){
    for(ll i=m-1;i>=0;i--){

        ll j;
        ll last=a1[n-1];
        for(j=n-2;j>=0&&a1[j]>a2[i];j--){
            a1[j+1]=a1[j];
        }
        if(j!=n-2 || last>a2[i]){
            a1[j+1]=a2[i];
            a2[i]=last;
        }
    }
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
 /*   vector<ll> a;
    a=mergetwosorted(arr1,arr2,n,m);
    for(ll i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
*/    cout<<endl;

    merge(arr1,arr2,n,m);
    print(arr1,n);
    cout<<" ";
    print(arr2,m);
}
