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

// O(N^2) time complexity O(R * C) space complexity (this is implementation based solution)
int OptimizerON2(v<v<int>> &arr){
    v<v<int>> temp(arr.size(),v<int>(arr[0].size(),0));
    int n=arr.size();
    int m=arr[0].size();
    int maxValue = INT_MIN;
    temp[n-1][m-1]= arr[n-1][m-1];
    // initializing last row
    int maxv = arr[n-1][m-1];
    for(int j=m-2;j>=0;j--){
        if(arr[n-1][j] > maxv){
            maxv=arr[n-1][j];
        }
        temp[n-1][j] = maxv;
    }
    // initializing last column
    maxv = arr[n-1][m-1];
    for(int i=n-2;i>=0;i--){
        if(arr[i][m-1] > maxv){
            maxv = arr[i][m-1];
        }
        temp[i][m-1] = maxv;
    }
    // preprocessing from bottom of temp matrix
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            if((temp[i+1][j+1]-arr[i][j]) > maxValue){
                maxValue = temp[i+1][j+1]-arr[i][j];
            }
            temp[i][j] = max(arr[i][j],max(temp[i][j+1],temp[i+1][j]));
        }
    }
    return maxValue;
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
    //cout<<"Pair value is :"<<bruteForcePairValue(mat);
    cout<<"Pair value is :"<<OptimizerON2(mat);
}
