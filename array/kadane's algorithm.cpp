#include "logic.cpp"
using namespace std;

// kadane's algorithm to find maximum sub continuous array sum
ll submaxsum(ll arr[],ll n){
    ll ans=0,max=0;
    for(ll i=0;i<n;i++){
        ans+=arr[i];
        if(max<ans) max=ans;
        if(ans<0) ans=0;
    }
    return max;
}
int main(){
    tell;
    ll n;
    cin>>n;
    ll arr[n];
    enterarray;
    getarray(arr,n);
    cout<<"Maximum sub continuous sum:"<<submaxsum(arr,n)<<endl;
}
