#include<bits/stdc++.h>
using namespace std;

pair<int,int> calculateNLogN(vector<int>&arr){
    pair<int,int> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]==arr[i+1]){
            ans.first = arr[i];
        }
        if(i+1 != arr[i] || i+2 == arr[i]){
            ans.second = (i+1==arr[i])?i+1:i+2;
        }
    }
    return ans;
}

int main(){

    cout<<"Enter Size of Array:->";
    int n;cin>>n;
    vector<int> arr(n,0);
    cout<<"Enter Array Element:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    pair<int,int> ans = calculateNLogN(arr);

    cout<<"repeating element is "<<ans.first<<" missing is "<<ans.second<<"\n";

}