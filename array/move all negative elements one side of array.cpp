#include<bits/stdc++.h>
using namespace std;
#define get int n; cin>>n; int arr[n]; for(int i=0;i<n;i++)cin>>arr[i];
#define print for(int i=0;i<n;i++) cout<<arr[i]<<" ";
#define tell cout<<"Enter Size Of Array:"<<endl;

// simple approach O(n)
void move(int arr[],int n){
    for(int i=0,j=0;j<n;j++){
        if(arr[j] < 0){
            swap(arr[i],arr[j]);
            i++;
        }
    }
}

// two pointer approach O(n)
// in this approach array should not contain '0'
void shift(int arr[],int l,int r){
    while(l <= r){
        if(arr[l] <=0 && arr[r] < 0) l++;
        else if(arr[l] >0 && arr[r] >0) r--;
        else if(arr[l] >0 && arr[r] <0){
            swap(arr[l],arr[r]);
            l++;
            r--;
        }else{
            // arr[l] < 0 && arr[r] > 0
            l++;
            r--;
        }
    }
}
int main(){
    tell;
    get;
    move(arr,n);
    print;
}
