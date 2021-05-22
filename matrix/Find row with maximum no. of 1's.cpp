#include<bits/stdc++.h>
using namespace std;
#define v vector
#define pb push_back

int numberOf1(v<v<int>> arr){
    int j=arr[0].size()-1;
    int max_ind=-1;
    for(int i=0;i<arr.size();i++){
        while(j>=0 && arr[i][j]==1){
            j--;
            max_ind=i;
        }
    }
    return max_ind;
}

int main(){
    cout<<"Enter Number of Row And Column:";
    int r,c;cin>>r>>c;
    cout<<"Enter Elements:\n";
    v<v<int>> arr;
    for(int i=0;i<r;i++){
        v<int> a(c,0);
        for(int j=0;j<c;j++){
            cin>>a[j];
        }
        arr.pb(a);
    }
    cout<<"Number of most 1 row index is :"<<numberOf1(arr)<<"\n";
}
