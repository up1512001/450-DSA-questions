#include "logic.cpp"
using namespace std;

int jump(ll arr[],ll n){
    ll ans=0;
    ll i=0;
    while(i<n-1){
        if(arr[i]==0) return -1;
        ans++;
        i+=arr[i];
    }
    return ans;
}
int main(){
    tell;
    ll n;
    cin>>n;
    ll arr[n];
    enterarray;
    getarray(arr,n);
    cout<<"Minimum Jump:"<<jump(arr,n)<<endl;
}
