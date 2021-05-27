#include<bits/stdc++.h>
using namespace std;
#define v vector
#define pb push_back
#define p pair

// O(N^4) time complexity and O(1) space complexity
int bruteForcePairValue(v<v<int>> &arr){
    int maxValue = INT_MIN;
    int ith=0,jth=0,ath=0,bth=0;
    for(int i=0;i<arr.size()-1;i++){
        for(int j=0;j<arr[0].size()-1;j++){
            for(int a=i+1;a<arr.size();a++){
                for(int b=j+1;b<arr[0].size();b++){
                    if(maxValue < (arr[a][b]-arr[i][j])){
                        maxValue = arr[a][b]-arr[i][j];
                        ath=a;
                        bth=b;
                        ith=i;
                        jth=j;
                    }
                }
            }
        }
    }
    cout<<arr[ath][bth]<<" "<<arr[ith][jth]<<"\n";
    cout<<"ith:"<<ith<<" jth:"<<jth<<" ath:"<<ath<<" bth:"<<bth<<"\n";
    return maxValue;
}
void print(v<v<int>> &a){
    cout<<"\nPriting Matrix:\n";
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[0].size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
int main(){
    cout<<"Enter Matrix Row and Column Size:\n";
    int r,c;cin>>r>>c;
    v<v<int>> mat;
    cout<<"Enter Matrix\n";
    for(int i=0;i<r;i++){
        v<int> t;
        for(int j=0;j<c;j++){
            int x;cin>>x;
            t.pb(x);
        }
        mat.pb(t);
    }
    print(mat);
    cout<<"Pair value is :"<<bruteForcePairValue(mat);
}
