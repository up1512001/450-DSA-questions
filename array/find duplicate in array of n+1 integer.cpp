#include"logic.cpp"
using namespace std;
// this is optimized version O(N) ans space O(1)
int dublicateElement(ll arr[],ll n){
    for(int i=0;i<n;i++){
        if(arr[abs(arr[i])]>=0){
            arr[abs(arr[i])]=-arr[abs(arr[i])];
        }else{
            return abs(arr[i]);
        }
    }
    return 0;
}
// brute force O(n Log n)
int bruteforce(ll arr[],ll n){
    sort(arr,arr+n);
    for(ll i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            return arr[i];
        }
    }
    return 0;
}
int main(){
    tell;
    ll n;
    cin>>n;
    enterarray;
    ll arr[n];
    getarray(arr,n);
    cout<<"Available Duplicate Element # Brute Force:"<<bruteforce(arr,n)<<endl;
    cout<<"Available Duplicate Element:"<<dublicateElement(arr,n)<<endl;

}
