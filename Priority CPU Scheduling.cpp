#include<bits/stdc++.h>
using namespace std;
#define v vector

void print(v<v<int>> &arr){
    cout<<"Sorted matrix:\n";
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

bool sortHelper(const v<int>&v1,const v<int>&v2){
    return v1[2]>v2[2];
}

void findWaiting(v<v<int>> &arr){
    arr[0][3] = 0;
    for(int i=1;i<arr.size();i++){
        arr[i][3] = arr[i-1][1] + arr[i-1][3];
    }
}

void turnAroundTime(v<v<int>> &arr){
    for(int i=0;i<arr.size();i++){
        arr[i][4] = arr[i][1] + arr[i][3];
    }
}

void priorityScheduling(v<v<int>> &arr){
    sort(begin(arr),end(arr),sortHelper);

    findWaiting(arr);
    turnAroundTime(arr);
    int tot_wat = 0,tot_tat=0;
    cout<<"Process || Bust || Priority || Waiting || Turn Around \n";
    for(int i=0;i<arr.size();i++){
        tot_wat+=arr[i][3];
        tot_tat+=arr[i][4];
        cout<<"   "<<arr[i][0]<<"\t   "<<arr[i][1]<<"\t     "<<arr[i][2]<<"\t\t"<<arr[i][3]<<"\t\t"<<arr[i][4]<<"\n";
    }
    cout<<"Average Waiting Time:->"<<(float)tot_wat/arr.size()<<"\n";
    cout<<"Average Turn Around Time:->"<<(float)tot_tat/arr.size()<<"\n";
    //print(arr);
}


int main(){
    cout<<"Enter Total Number of Process:\n";
    int n;cin>>n;
    v<v<int>> arr;
    cout<<"\"Enter All Details\"\n";
    for(int i=0;i<n;i++){
        cout<<"Enter Process: ";
        int x;cin>>x;
        cout<<"Enter Bust: ";
        int y;cin>>y;
        cout<<"Enter Priority: ";
        int p;cin>>p;
        arr.push_back({x,y,p,0,0});
    }
    priorityScheduling(arr);

}
