#include<bits/stdc++.h>
using namespace std;
#define v vector
#define pb push_back

// using set O(R * C * Log N ) time and O(R * C) space
int usingSet(v<v<int>> &arr,int k){
    set<int> s;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            s.insert(arr[i][j]);
        }
    }
    int i=0;
    for(auto it=s.begin();it!=s.end();it++,i++){
        if(i==(k-1)) return *it;
    }
    return 0;
}

// using min heap time O(K Log N) and space O(N)
/*
struct HeapNode{
    int val;
    int r;
    int c;
};
void minHeapify(HeapNode harr[],int i, int heap_size){
    int l = i*2+1;
    int r = i*2+2;
    int smallest = i;
    if(l<heap_size && harr[l].val<harr[i].val){
        smallest = l;
    }
    if(r<heap_size && harr[r].val == 0){
        minHeapify(harr,i,heap_size);
        i--;
    }
}
int minHeapUsing(v<v<int>> &arr,int k){
    if(k<0 && k>arr.size()*arr.size()){
        //cout<<"K value:->"<<k<<"\n";
        return INT_MAX;
    }
    HeapNode harr[arr.size()];
    for(int i=0;i<arr.size();i++){
        harr[i] = {arr[0][i],0,i};
    }
    HeapNode hr;
    for(int i=0;i<k;i++){
        hr = harr[0];

        int nextVal = (hr.r < (arr.size()-1)) ? arr[hr.r+1][hr.c]:INT_MAX;
        cout<<"nextVal:->"<<nextVal<<"\n";
        harr[0] = {nextVal,(hr.r)+1,(hr.c)+1};

        minHeapify(harr,0,arr.size());
    }
    return hr.val;
}
*/

int main(){
    v<v<int>> arr;
    cout<<"Enter Row and Column size:\n";
    int r,c;cin>>r>>c;
    cout<<"Enter Matrix:\n";
    for(int i =0;i<r;i++){
        v<int> t;
        for(int j=0;j<c;j++){
            int x;cin>>x;
            t.pb(x);
        }
        arr.pb(t);
    }
    cout<<"Enter K Value :";
    int k;cin>>k;
    //cout<<"K th Smallest Element :"<<usingSet(arr,k);
    cout<<"K th Smallest Element :"<<minHeapUsing(arr,k);
}
