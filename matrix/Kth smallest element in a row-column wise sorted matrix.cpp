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

// this priority queue will not count duplicate value as separate values
int UsingPriorityQueue(v<v<int>> &arr,int k){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<arr.size();i++){
        pq.push({arr[i][0],i});
    }
    v<int> idx(k,0);
    set<int> s;
    while(!pq.empty()){
        pair<int,int> x = pq.top();
        pq.pop();
        if(s.empty()){
            s.insert(x.first);
            k--;
        }else if(s.find(x.first) == s.end()){
           // cout<<"Hello..."<<"\n";
            s.insert(x.first);
            k--;
        }
        //k--;
        if(k==0) return x.first;
        if(idx[x.second]+1 < arr[x.second].size()){
            pq.push({arr[x.second][idx[x.second]+1],x.second});
        }
        idx[x.second]++;
    }
    return 0;
}


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
    cout<<"K th Smallest Element :"<<UsingPriorityQueue(arr,k);
}
