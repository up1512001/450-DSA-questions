#include<bits/stdc++.h>
using namespace std;

// O(N) time
int linearN(vector<int>&arr,int x){

    for(int i=0;i<arr.size();i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}

// O(Log N) time
int binaryLogN(vector<int>&arr,int x){

    int i=0,j=arr.size()-1;
    while(i<j){
        int mid = i+(j-i)/2;
        if(arr[mid]>arr[j]){
            i=mid+1;
        }else{
            j=mid;
        }
    }
    //cout<<i<<"\n";
    int rot = i;
    i=0;j=arr.size()-1;
    while(i<=j){
        int mid = i+(j-i)/2;
        int realmid = (mid+rot)%arr.size();
        if(arr[realmid]==x) return realmid;
        else if(arr[realmid]<x) i=mid+1;
        else j=mid-1;
    }
    return -1;
}

int main(){

    cout<<"Enter Size of Array:->";
    int n;cin>>n;
    cout<<"Enter Array:\n";
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Enter Element for search :->";
    int x;cin>>x;

    cout<<"index is :->"<<linearN(arr,x)<<"\n";
    cout<<"index is :->"<<binaryLogN(arr,x)<<"\n";

}
