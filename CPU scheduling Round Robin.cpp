#include<bits/stdc++.h>
using namespace std;
# define v vector
#define pb push_back
void print(v<v<int>> arr);
v<v<int>> turnAround(v<v<int>> arr);
v<v<int>> watingTime(v<v<int>> arr,int q);
void detalis(v<v<int>> arr,int q);
v<v<int>> watingTime(v<v<int>> arr,int q){
    for(int i=0;i<arr.size();i++){
        arr[i][4]=arr[i][1];
    }
    print(arr);
    int t=0;
    while(true){
        bool f=true;
        for(int i=0;i<arr.size();i++){
            if(arr[i][4]>0){
                f=false;
                if(arr[i][4]>q){
                    t+=q;
                    arr[i][4] -= q;
                }else{
                    t+=arr[i][4];
                    arr[i][2]=t-arr[i][1];
                    arr[i][4]=0;
                }
            }
        }
        if(f==true)break;
    }
    //print(arr);
    return arr;
}

v<v<int>> turnAround(v<v<int>> arr){
    for(int i=0;i<arr.size();i++){
        arr[i][3]=arr[i][1]+arr[i][2];
    }
    return arr;
}
void detalis(v<v<int>> arr,int q){
    //cout<<arr.size()<<"\n";
    //cout<<q<<"\n";
    //print(arr);
    arr = watingTime(arr,q);
    //print(arr);
    arr = turnAround(arr);
    //print(arr);
    int tot_wt=0,tot_tutn=0;
    cout<<"Process || Bust || Waiting || Turn Around\n";
    for(int i=0;i<arr.size();i++){
        tot_wt+=arr[i][2];
        tot_tutn+=arr[i][3];
        cout<<"  "<<arr[i][0]<<"\t   "<<arr[i][1]<<"\t   "<<arr[i][2]<<"\t\t"<<arr[i][3]<<"\n";
    }
    cout<<"Average Waiting Time :"<<tot_wt/(float)(arr.size())<<"\n";
    cout<<"Average Turn Around Time :"<<tot_tutn/(float)(arr.size())<<"\n";
}
void print(v<v<int>> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<" "<<arr[i][3]<<" "<<arr[i][4]<<"\n";
    }
}
int main(){
    v<v<int>> arr;
    cout<<"Enter Number Of Process:\n";
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter Process:\n";
        int x;cin>>x;
        cout<<"Enter Bust:\n";
        int y;cin>>y;
        arr.pb({x,y,0,0,0});
    }
    cout<<"Enter Quantum:\n";
    int q;cin>>q;
    detalis(arr,q);
}
