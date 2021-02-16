#include<bits/stdc++.h>
using namespace std;
int min(int arr[],int n){
    int m=arr[0];
    for(int i=1;i<n;i++){
        if(m > arr[i]) m=arr[i];
    }
    return m;
}
int max(int arr[],int n){
    int m=arr[0];
    for(int i=0;i<n;i++){
        if(m < arr[i]) m=arr[i];
    }
    return m;
}
// min and max function will take O(n) time
int main(){
    int n;
    cout<<"Enter Size of Array:"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Min Value:"<<min(arr,n)<<endl;
    cout<<"Max Value:"<<max(arr,n)<<endl;
}
