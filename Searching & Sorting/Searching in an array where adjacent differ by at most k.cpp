#include<bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> arr,int k,int x){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}
int optimizedSearch(vector<int> arr,int k,int x){
    int i=0;
    while(i<arr.size()){
        if(arr[i]==x){
            return i;
        }
        i += max(1,abs(arr[i]-x)/k);
    }
    return -1;
}

int main(){

    cout<<"Enter Size of Array:->";
    int n;cin>>n;
    vector<int> arr(n,0);
    cout<<"Enter Array:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter K Value :->";
    int k;cin>>k;
    cout<<"\nEnter Searching Value :->";
    int x;cin>>x;

    cout<<"Simple Approach in O(N) time output index will be :->"<<linearSearch(arr,k,x)<<"\n";
    cout<<"Optimized Approach output will be :->"<<optimizedSearch(arr,k,x)<<"\n";


}