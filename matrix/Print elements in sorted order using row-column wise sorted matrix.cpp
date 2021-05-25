#include<bits/stdc++.h>
using namespace std;
#define v vector
#define pb push_back

// time complexity will be O(R * C) and space will be O(R*C)
v<int> sortMatrix(v<v<int>> arr){
    v<int> ret;
    map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            mp[arr[i][j]]++;
        }
    }
    auto itr = mp.begin();
    while(itr!=mp.end()){
        if(itr->second >0){
            ret.pb(itr->first);
            itr->second--;
        }else{
            itr++;
        }
    }
    return ret;
}

// time complexity will be O(N ^ 3) N^2 for calculation and N for traversal space complexity will be O(1)
void calculate(v<v<int>>& arr,int i,int j){
    int belowVal = (i+1 < arr.size()) ? arr[i+1][j] : INT_MAX;
    int rightVal = (j+1 < arr[0].size()) ? arr[i][j+1] : INT_MAX;

    if(belowVal==INT_MAX && rightVal==INT_MAX) return;

    if(belowVal < rightVal){
        arr[i][j]=belowVal;
        arr[i+1][j] = INT_MAX;
        calculate(arr,i+1,j);
    }else{
        arr[i][j]=rightVal;
        arr[i][j+1]=INT_MAX;
        calculate(arr,i,j+1);
    }
}
void print(v<v<int>>& arr){
    cout<<"\nPrinting Matrix:";
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
    }
    cout<<"\n";
}
int retValue(v<v<int>>& arr){
    int val = arr[0][0];
    //cout<<"\n arr[0][0]="<<arr[0][0]<<"\n";
    arr[0][0]=INT_MAX;
    //print(arr);
    calculate(arr,0,0);
    //print(arr);
    return val;
}
void printSorted(v<v<int>>& arr){
    //v<int> ret;
    cout<<"Sorted :->";
    for(int i=0;i<arr.size()*arr[0].size();i++){
        cout<<retValue(arr)<<" ";
    }
    cout<<"\n";
    //ret.pb(retValue(arr));
}
// **********************************************************************
int main(){
    v<v<int>> arr;
    cout<<"Enter Number of Raws and Columns of row-column sorted matrix:\n";
    int r,c;cin>>r>>c;
    cout<<"Enter Matrix:\n";
    for(int i=0;i<r;i++){
        v<int> temp;
        for(int j=0;j<c;j++){
            int x;cin>>x;
            temp.pb(x);
        }
        arr.pb(temp);
    }
    printSorted(arr);
    //v<int> ans = printSorted(arr);
    //cout<<"Sorted Array\n";
    //for(int i=0;i<ans.size();i++){
      //  cout<<ans[i]<<" ";
    //}
}
