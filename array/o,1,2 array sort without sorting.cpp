#include<bits/stdc++.h>
using namespace std;
#define get int n; cin>>n; int arr[n]; for(int i=0;i<n;i++)cin>>arr[i];
#define print for(int i=0;i<n;i++) cout<<arr[i]<<" ";

// simple solution with Two Iteration of array
void sort(int arr[],int n){
    int a=0,b=0,c=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) a++;
        else if(arr[i]==1)b++;
        else if(arr[i]==2)c++;
    }
    for(int i=0;i<n;i++){
        if(a != 0){
            arr[i]=0;
            a--;
        }else if(b != 0){
            arr[i]=1;
            b--;
        }else if(c != 0){
            arr[i]=2;
            c--;
        }
    }
}
// dutch nation flag algorithm O(n)
void sort012(int arr[],int n){
    int lo=0;
    int hi=n-1;
    int mid=0;
    while(mid <= hi){
        switch(arr[mid]){
        case 0:
            swap(arr[lo++],arr[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(a[mid],a[hi--]);
            break;
        }
    }
}
int main(){
    cout<<"Enter Size of Array:"<<endl;
    get;
    sort012(arr,n);
    print;
    cout<<endl;
}
