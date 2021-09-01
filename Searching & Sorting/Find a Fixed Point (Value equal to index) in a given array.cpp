#include<bits/stdc++.h>
using namespace std;

// O(N) time
int valueEqualIndex(vector<int>&arr){

    for(int i=0;i<arr.size();i++){
        if(i+1==arr[i]){
            return arr[i];
        }
    }
    return -1;

}

// O(Log N) time if given array is sorted
int LogNTime(vector<int>&arr){

    int i=0,j=arr.size()-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(mid == arr[mid]){
            return mid;
        }else if(arr[mid]>mid){
            j=mid-1;
        }else{
            i=mid+1;
        }
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

    cout<<"Element with it's value equal to index value is :->"<<valueEqualIndex(arr)<<"\n";
    cout<<"Element with it's value equal to index value is :->"<<LogNTime(arr)<<"\n";


}
