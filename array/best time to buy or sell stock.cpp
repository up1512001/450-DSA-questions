#include "logic.cpp"

// O(N)
void sol(ll arr[],ll n){
    ll currPro=INT_MAX;
    ll max=0;
    for(ll i=0;i<n;i++){
        if(currPro > arr[i]){
            currPro=arr[i];
        }
        if(max < arr[i]-currPro){
            max=arr[i]-currPro;
        }
    }
    cout<<"Maximum Profit:"<<max<<endl;
}

int main(){
    tell;
    ll n;
    cin>>n;
    ll arr[n];
    enterarray;
    getarray(arr,n);

    sol(arr,n);

}
