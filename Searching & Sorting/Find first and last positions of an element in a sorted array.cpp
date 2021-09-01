#include<bits/stdc++.h>
using namespace std;

// O(N) time approach
pair<int,int> inNTime(vector<int>&arr,int x){

    pair<int,int> ans;
    int m=INT_MAX,n=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(x==arr[i]){
            m = min(i,m);
            n = max(i,n);
        }
    }
    ans.first = m;
    ans.second = n;

    return ans;

}

// O(Log N) approach
pair<int,int> inLogNTime(vector<int>&arr,int x){

    pair<int,int> ans;
    int m=INT_MAX,n=INT_MIN;
    int i=0,j=arr.size()-1;
    // first occurrence
    while(i<=j){
        int mid=i+(j-i)/2;
        if(x==arr[mid]){
            m=min(m,mid);
            j=mid-1;
        }else if(arr[mid]>x){
            j = mid-1;
        }else{
            i=mid+1;
        }
    }
    i=0;j=arr.size()-1;
    // last occurrence
    while(i<=j){
        int mid=i+(j-i)/2;
        if(x==arr[mid]){
            n=max(n,mid);
            i=mid+1;
        }else if(arr[mid]>x){
            j = mid-1;
        }else{
            i=mid+1;
        }
    }

    ans.first = m;
    ans.second = n;

    return ans;

}

int main(){

    cout<<"Enter Size of Array :->";
    int n;cin>>n;

    vector<int> arr(n,0);
    cout<<"Enter Array in sorted manner:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter Value to find:\n";
    int x;cin>>x;
    pair<int,int> ans1 = inNTime(arr,x);
    cout<<"Answer is :"<<ans1.first<<" "<<ans1.second<<"\n";
    pair<int,int> ans2 = inLogNTime(arr,x);
    cout<<"Answer is :"<<ans2.first<<" "<<ans2.second<<"\n";

}
