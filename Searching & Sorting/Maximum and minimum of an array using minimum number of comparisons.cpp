#include<bits/stdc++.h>
using namespace std;

pair<int,int> calMinMax(vector<int>&arr){

    pair<int,int> ret;
    if(arr.size()==0){
        ret.first=arr[0];
        ret.second=arr[0];
    }else{

        if(arr[0]>=arr[1]){
            ret.first = arr[1];
            ret.second = arr[0];
        }else{
            ret.first = arr[0];
            ret.second = arr[1];
        }
        for(int i=2;i<arr.size();i++){
            if(ret.first>arr[i]){
                ret.first = arr[i];
            }else if(ret.second<arr[i]){
                ret.second = arr[i];
            }
        }
    }
    return ret;

}

int main(){

    cout<<"Enter Size of Array :->";
    int n;cin>>n;
    cout<<"Enter Array:\n";
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    pair<int,int> ans = calMinMax(arr);
    cout<<"Minimum is :"<<ans.first<<" Maximum is :"<<ans.second<<"\n";



}
