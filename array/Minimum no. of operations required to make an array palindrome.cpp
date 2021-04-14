#include "logic.cpp"

bool sol(ll arr[],ll n){
    for(ll i=0;i<n;i++){
        ll ans = 0;
        ll temp = arr[i];
        while(temp > 0){
            ll r = (temp % 10);
            temp/=10;
            ans = (ans*10)+r;
        }
        if(ans != arr[i]) return false;
    }
    return true;
}
int main(){
    tell;
    ll n;cin>>n;
    enterarray;
    ll arr[n];
    getarray(arr,n);
    cout<<"(1 for YES 0 for NO)"<<endl;
    cout<<"Given Array is Palindrome ? :-->>"<<sol(arr,n)<<endl;
}
