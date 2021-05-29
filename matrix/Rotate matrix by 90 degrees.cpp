#include<bits/stdc++.h>
using namespace std;
#define v vector
#define pb push_back

// using O(R * C) extra space
v<v<int>> BruteForceRotateLeft(v<v<int>> &arr){
    v<v<int>> ret(arr.size(),v<int>(arr[0].size(),0));
    int a=0,b=0;
    for(int j=arr[0].size()-1;j>=0;j--,a++){
        for(int i=0;i<arr.size();i++,b++){
            ret[a][b]=arr[i][j];
        }
        b=0;
    }
    return ret;

}

v<v<int>> BruteForceRotateRight(v<v<int>> &arr){
    v<v<int>> ret(arr.size(),v<int>(arr[0].size(),0));
    int a=0,b=0;
    for(int j=0;j<arr[0].size();j++,a++){
        for(int i=arr.size()-1;i>=0;i--,b++){
            ret[a][b]=arr[i][j];
        }
        b=0;
    }
    return ret;

}


// optimized O(N^2) time and O(1) space approach
v<v<int>> OptimizedRotateRight(v<v<int>> &arr){
    // gives transpose of matrix
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<i;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    // reversing transpose
    for(int i=0;i<arr.size();i++){
        reverse(begin(arr[i]),end(arr[i]));
    }
    return arr;
}

v<v<int>> OptimizedRotateLeft(v<v<int>> &arr){
    // gives transpose of matrix
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<i;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    // reversing transpose
    for(int j=0;j<arr[0].size();j++){
        for(int i=0,k=arr.size()-1;i<k;i++,k--){
            swap(arr[i][j],arr[k][j]);
        }
    }
    return arr;
}

int main(){
    v<v<int>> arr;
    cout<<"Enter Row and Column size:\n";
    int r,c;cin>>r>>c;
    cout<<"Enter Matrix:\n";
    for(int i=0;i<r;i++){
        v<int> t;
        for(int j=0;j<c;j++){
            int x;cin>>x;
            t.pb(x);
        }
        arr.pb(t);
    }
    v<v<int>> ans = BruteForceRotateRight(arr);
    cout<<"Rotated Matrix :\n";
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}
