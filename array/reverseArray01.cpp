#include<bits/stdc++.h>
using namespace std;
void reverse(int arr[],int n){
// this will reverse in O(n/2) time
// this is iterative approach
    for(int i=0,j=n-1;i<j;i++,j--){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}
void rev(int arr[],int s,int e){
    // recursive approach O(n) time and O(n/2) space
    if(s > e) return;
    else{
        swap(arr[s],arr[e]);
        rev(arr,s+1,e-1);
    }
}
int main(){
    int n;
    cout<<"Enter Size of Array:"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    reverse(arr,n);
    cout<<"Reversed Array by Iterative:"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    rev(arr,0,n-1);
    cout<<"Reversed array by recursion"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
