#include<bits/stdc++.h>
using namespace std;

int MCM(vector<int> &arr,int i,int j){

    if(i>=j){
        return 0;
    }
    int mn = INT_MAX;
    for(int k=i;k<j;k++){
        int temp = MCM(arr,i,k) + MCM(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        mn = min(mn,temp);
    }
    return mn;

}

int main(){

    cout<<"Enter size of array:->";
    int n;cin>>n;
    vector<int> arr(n,0);
    cout<<"Enter Array:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Minimum multiplications are :->"<<MCM(arr,1,n-1)<<"\n";
}
