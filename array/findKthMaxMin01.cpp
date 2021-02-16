#include<bits/stdc++.h>
using namespace std;
// 3 method to find K th max or min
// 1. if array does not contain duplicate then sort array and return arr[k+1] complexity:O(n log n)
// 2. max heap and min heap complexity:O(n + k log n) for max heap O(n + (n-k+1) log (n-k+1)) for min heap
// 3. quick select complexity: O(n)
// sorting solution
int bySorting_Min(int arr[],int n,int k){
    sort(arr,arr+n);
    return arr[k-1];
}
int bySorting_Max(int arr[],int n,int k){
    sort(arr,arr+n);
    return arr[n-k];
}

// heap solution
void heapify(int arr[],int n,int i){
    int largest=i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n && arr[l] > arr[largest]) largest=l;
    if(r<n && arr[r] > arr[largest]) largest=r;
    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapsort(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i++){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
// Complexity: O(n log k) for minHeap and maxHeap
int maxHeap(int arr[],int size,int k){
    priority_queue<int> maxH;
    for(int i=0;i<size;i++){
        maxH.push(arr[i]);
        if(maxH.size() > k){
            maxH.pop();
        }
    }
    return maxH.top();
}
int minHeap(int arr[],int size,int k){
    priority_queue<int,vector<int>,greater<int> > minH;
    for(int i=0;i<size;i++){
        minH.push(arr[i]);
        if(minH.size() > k){
            minH.pop();
        }
    }
    return minH.top();
}

// Quick select best case O(n) worst case O(n*n) or O(N^2)
// below code is not WORKING OK UT date: 13/02/2021
int quickselect(int arr[],int start,int end,int k){
    int i,j,key,temp;
    bool flag=true;
    if(start < end){
        while(flag == true){
            i=start;
            j=end+1;
            key=arr[end-1];
            while(key >= arr[i]) i++;
            j--;
            while(key < arr[j]) j--;
            if(i<j){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }else{
                flag=false;
            }
        }
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        if(k == j) return arr[j];
        else if(k-1 < j) quickselect(arr,start,j-1,k);
        else if(k-1 > j) quickselect(arr,j+1,end,k);
    }
}

int main(){
    int n;
    cout<<"Enter Size of Array:"<<endl;
    cin>>n;
    cout<<"Enter K Value:"<<endl;
    int k; cin>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
   // cout<<k<<"th min:"<<bySorting_Min(arr,n,k)<<endl;
   // cout<<k<<"th max:"<<bySorting_Max(arr,n,k)<<endl;
   //heapsort(arr,n);
   //cout<<"K th Smallest Element:"<<maxHeap(arr,n,k)<<endl;
   //cout<<"K th Largest Element"<<minHeap(arr,n,k)<<endl;
   cout<<"Your Element:"<<quickselect(arr,0,n,k)<<endl;
}
