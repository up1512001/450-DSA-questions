#include "logic.cpp"
ll maxProductArray(ll arr[],ll n){
    ll max_so_far=0;
    ll max_ending_here=1;
    ll min_ending_here=1;
    ll flag=0;
    ll c=1;
    for(ll i=0;i<n;i++){
        if(arr[i]>0){
            max_ending_here = max_ending_here*arr[i];
            min_ending_here = min(min_ending_here*arr[i],c);
            flag=1;
        }
        else if(arr[i]==0){
            max_ending_here=1;
            min_ending_here=1;
        }
        else{
            ll temp = max_ending_here;
            max_ending_here = max(min_ending_here*arr[i],c);
            min_ending_here = temp*arr[i];
        }

        if(max_so_far < max_ending_here){
            max_so_far=max_ending_here;
        }
    }
    if(flag==0 && max_so_far==0){
        return 0;
    }
    return max_so_far;
}
int main(){
    tell;
    ll n;
    cin>>n;
    enterarray;
    ll arr[n];
    getarray(arr,n);

    cout<<"Maximum Product of Sub array is :"<<maxProductArray(arr,n)<<endl;
}
