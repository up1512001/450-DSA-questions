#include "logic.cpp"

// O(N Log N) time O(1) space
void sol1(ll arr[],ll n,ll low,ll high){
    sort(arr,arr+n);
    return;
}

// O(N) time and O(1) space
void sol2(ll arr[],ll n,ll low,ll high){
    ll start=0,end=n-1;
    for(ll i=0;i<=end;){
        if(arr[i]<low){
            swap(arr[i++],arr[start++]);
        }else if(arr[i]>high){
            swap(arr[i],arr[end--]);
        }else{
            i++;
        }
    }
}
int main(){
    tell;
    ll n; cin>>n;
    ll arr[n];
    enterarray;
    getarray(arr,n);
    cout<<"Enter Low value:";
    ll low; cin>>low;
    cout<<"Enter High Value:";
    ll high; cin>>high;
    //sol1(arr,n,low,high);
    sol2(arr,n,low,high);
    print(arr,n);
}
