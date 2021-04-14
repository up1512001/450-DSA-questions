#include"logic.cpp"
using namespace std;
#include<unordered_map>
// O(N) time and O(N) space
void sol();
ll possiblePair(ll arr[],ll n,ll sum){
    unordered_map<ll,ll> m;
    for(ll i=0;i<n;i++){
        m[arr[i]]++;
    }
    ll cnt=0;
    for(ll i=0;i<n;i++){
        cnt+=m[sum-arr[i]];
        if((sum-arr[i])== arr[i]){
            cnt--;
        }
    }
    return cnt/2;
}
void sol(){
    tell;
    ll n;
    cin>>n;
    ll arr[n];
    enterarray;
    getarray(arr,n);
    cout<<"Enter Sum Value:"<<endl;
    ll sum;
    cin>>sum;
    cout<<"Number Of Possible Pairs:"<<possiblePair(arr,n,sum)<<endl;
}
int main(){
    sol();
}
