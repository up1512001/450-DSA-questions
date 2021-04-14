#include "logic.cpp"
// O(N) time and O(N) space
ll sol(ll arr[],ll n){
    ll left[n];
    ll right[n];
    left[0]=arr[0];
    right[n-1]=arr[n-1];
    for(ll i=1;i<n;i++){
        left[i]=max(left[i-1],arr[i]);
    }
    for(ll i=n-2;i>=0;i--){
        right[i]=max(right[i+1],arr[i]);
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        ans += (min(left[i],right[i])-arr[i]);
    }
    return ans;
}

// O(N) time O(1) space
ll sol1(ll arr[],ll n){
    ll ans=0;
    ll left_max=0,right_max=0;
    ll i=0,j=n-1;
    while(i<j){
        if(arr[i]<arr[j]){
            if(arr[i]>left_max){
                left_max=arr[i];
            }else{
                ans += left_max-arr[i];
            }
            i++;
        }else{
            if(arr[j]>right_max){
                right_max=arr[j];
            }else{
                ans += right_max-arr[j];
            }
            j--;
        }
    }
    return ans;
}
int main(){
    tell;
    ll n; cin>>n;
    ll arr[n];
    enterarray;
    getarray(arr,n);

    cout<<"Water that can store:"<<sol1(arr,n)<<endl;
}
