#include "logic.cpp"
using namespace std;

// Largest sum of sub continues array
// Brute force way O(n*n)
ll subArraySum(ll arr[],ll n){
    ll ans=0,sum=0;
    for(ll i=0;i<n-1;i++){
        sum=arr[i];
        for(ll j=i+1;j<n;j++){
            sum+=arr[j];
            if(ans < sum){
                ans=sum;
            }
        }
        sum=0;
    }
    return ans;
}
// optimized way of sub continues array sum
// Kandane's Algorithm O(n)
ll subArraySum1(ll arr[],ll n){
    ll ans=INT_MIN;
    ll max_ending_here=0;
    for(ll i=0;i<n;i++){
        max_ending_here+=arr[i];
        if(ans<max_ending_here){
            ans=max_ending_here;
        }
        if(max_ending_here < 0){
            max_ending_here=0;
        }
    }
    return ans;
}
int main(){
    tell;
    ll n;
    cin>>n;
    ll arr[n];
    getarray(arr,n);
    cout<<"Largest Sub continues Array Sum:"<<subArraySum1(arr,n)<<endl;
}
