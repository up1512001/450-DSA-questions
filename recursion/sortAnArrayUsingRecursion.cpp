#include<bits/stdc++.h>
using namespace std;

void ins(vector<int>&arr,int temp){
    if(arr.size()==0 || arr[arr.size()-1]<=temp){
        arr.push_back(temp);
        return;
    }
    int val = arr[arr.size()-1];
    arr.pop_back();
    ins(arr,temp);
    arr.push_back(val);
    return;
}

void srt(vector<int> &arr){
    if(arr.size()==1){
        return ;
    }
    int temp = arr[arr.size()-1];
    arr.pop_back();
    srt(arr);
    ins(arr,temp);
    return;
}

int main(){
    cout<<"Enter Size of Array:";
    int n;cin>>n;
    vector<int> arr(n);
    cout<<"Enter Array:\n";
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    srt(arr);
    cout<<"Sorted Array:\n";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}


