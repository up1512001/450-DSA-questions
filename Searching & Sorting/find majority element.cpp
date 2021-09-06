#include<bits/stdc++.h>
using namespace std;

// N Log N approach
int majority(vector<int> arr){
    sort(begin(arr),end(arr));
    int ans=-1,cnt=1;
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]==arr[i+1]){
            cnt++;
        }else{
            if(cnt>(arr.size()/2)){
                ans=arr[i];
            }
            cnt=1;
        }
    }
    return ans;
}

int mooresVotingAlgorithm(vector<int>arr){

    int major_index = 0,cnt=1;
    for(int i=1;i<arr.size();i++){
        if(arr[major_index] == arr[i]){
            cnt++;
        }else{
            cnt--;
        }
        if(cnt == 0){
            major_index = i;
            cnt = 1;
        }
    }
    cnt = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[major_index] == arr[i]){
            cnt++;
        }
    }
    if(cnt >(arr.size()/2)) return arr[major_index];
    return -1;

}

int main(){

    cout<<"Enter Array Size:->";
    int n;cin>>n;
    cout<<"Enter Array :\n";
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Majority elements are :->"<<majority(arr)<<"\n";
    cout << "Majority elements are :->" << mooresVotingAlgorithm(arr) << "\n";
}