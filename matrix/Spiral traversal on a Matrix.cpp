//#include "E:\codechef and codeforces also leetcode\love babbar 450 questions\logic.cpp"
#include<bits/stdc++.h>
using namespace std;
#define ll int
#define C 10


/*
// WRONG IMPLEMENTATION
void spiral(ll r,ll c,vector<vector<ll> >a){
    ll dir=0;
    ll top=0,left=0,down=r-1,right=r-1;
    while(top<=down && left<=right){
        if(dir == 0){
            for(ll i=left;i<=right;i++){
                cout<<a[top][i]<<" ";
            }
            top++;
        }else if(dir == 1){
            for(ll i=top;i<=down;i++){
                cout<<a[i][right]<<" ";
            }
            right--;
        }else if(dir == 2){
            for(ll i=right;i>=left;i--){
                cout<<a[down][i]<<" ";
            }
            down--;
        }else if(dir == 3){
            for(ll i=down;i>=top;i--){
                cout<<a[i][left]<<" ";
            }
            left++;
        }
        dir = (dir + 1)%4;
    }
}
*/
// O(M * N) time and O(1) space
void spiral(ll m,ll n,vector<vector<ll> >a){
    ll i,k=0,l=0;
    while(k<m && l<n){
        for(i=l;i<n;++i){
            cout<<a[k][i]<<" ";
        }
        k++;
        for(i=k;i<m;++i){
            cout<<a[i][n-1]<<" ";
        }
        n--;
        if(k<m){
            for(i=n-1;i>=l;--i){
                cout<<a[m-1][i]<<" ";
            }
            m--;
        }
        if(l<n){
            for(i=m-1;i>=k;--i){
                cout<<a[i][l]<<" ";
            }
            l++;
        }
    }
}



int main(){
    ll r,c;
    cout<<"Enter Rows and Columns:";
    cin>>r>>c;
    //ll arr[r][c];

    vector<vector<ll> > arr;
    cout<<"Enter Matrix:"<<endl;
    for(ll i=0;i<r;i++){
        vector <ll> a;
        for(ll j=0;j<c;j++){
            ll x;
            cin>>x;
            a.push_back(x);
        }
        arr.push_back(a);
        a.clear();
    }

   /* ll arr[r][c];
    cout<<"Enter Matrix:"<<endl;
    for(ll i=0;i<r;i++){
        for(ll j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }*/
    spiral(r,c,arr);
}
