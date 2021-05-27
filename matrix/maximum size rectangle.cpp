#include<bits/stdc++.h>
//#include "MAH.h"
using namespace std;
#define vi vector
#define pb push_back
#define p pair
#define s stack
void print(vi<int> t);
vi<int> NSL(vi<int> &arr){
    vi<int> left;
    s<p<int,int>> s;
    int sudoind=-1;
    for(int i=0;i<arr.size();i++){
        if(s.size()==0){
            left.pb(sudoind);
        }else if(s.size()>0 && s.top().first < arr[i]){
            left.pb(s.top().second);
        }else if(s.size() > 0 && s.top().first >= arr[i]){
            while(s.size()>0 && s.top().first >= arr[i]){
                s.pop();
            }
            if(s.size()==0){
                left.pb(sudoind);
            }else{
                left.pb(s.top().second);
            }
        }else{
            left.pb(s.top().second);
        }
        s.push({arr[i],i});
    }
    //print(left);
    return left;
}
// NSR (nearest smaller to right)
vi<int> NSR(vi<int>& arr){
    vi<int> right;
    s<p<int,int>> s;
    int sudoind=arr.size();
    for(int i=arr.size()-1;i>=0;i--){
        if(s.size()==0){
            right.pb(sudoind);
        }else if(s.size()>0 && s.top().first < arr[i]){
            right.pb(s.top().second);
        }else if(s.size() > 0 && s.top().first >= arr[i]){
            while(s.size()>0 && s.top().first >= arr[i]){
                s.pop();
            }
            if(s.size()==0){
                right.pb(sudoind);
            }else{
                right.pb(s.top().second);
            }
        }else{
            right.pb(s.top().second);
        }
        s.push({arr[i],i});
    }
    //print(right);
    return right;
}
int MAH(vi<int> &arr){
    vi<int> left = NSL(arr);
    vi<int> right = NSR(arr);
    reverse(begin(right),end(right));
    vi<int> width(arr.size());
    for(int i=0;i<width.size();i++){
        width[i]=right[i]-left[i]-1;
    }
    int mx=INT_MIN;
    //print(left);
    //print(right);
    //print(width);
    for(int i=0;i<arr.size();i++){
        mx = max(mx,width[i]*arr[i]);
    }
    return mx;
}

int binaryMatrixArea(vi<vi<int>> arr){
    int mx = INT_MIN;
    vi<int> t(arr[0].size(),0);
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            if(arr[i][j]==0){
                t[j]=0;
            }else{
                t[j]+=arr[i][j];
            }
        }
        print(t);
        mx = max(mx,MAH(t));
    }
    return mx;
}
void print(vi<int> t){
    cout<<"\n printing Vector: ";
    for(int i=0;i<t.size();i++)
        cout<<t[i]<<" ";
    cout<<"\n";
}
int main(){
    cout<<"Enter row and column size\n";
    int r,c;cin>>r>>c;
    vi<vi<int>> arr;
    cout<<"Enter Matrix\n";
    for(int i=0;i<r;i++){
        vi<int> t;
        for(int j=0;j<c;j++){
            int x;cin>>x;
            t.pb(x);
        }
        arr.pb(t);
    }
    cout<<"Maximum area is :"<<binaryMatrixArea(arr)<<"\n";
}
