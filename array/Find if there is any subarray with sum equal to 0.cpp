#include "logic.cpp"
#include<unordered_set>
// here we are finding continuous sub array with sum equal to zero
// O(N) time and O(N) space complexity
bool sol(ll arr[],ll n){
    unordered_set<ll> a;
    int sum=0;
    for(ll i=0;i<n;i++){
        sum+=arr[i];
        if(sum == 0 ||(a.find(sum) != a.end())){
            return true;
        }
        a.insert(sum);
    }
    return false;
}
int main(){
    tell;
    ll n;cin>>n;
    enterarray;
    ll arr[n];
    getarray(arr,n);

    cout<<"Answer:"<<sol(arr,n)<<endl;;
}
