#include<bits/stdc++.h>
using namespace std;

pair<int,int> calculateNLogN(vector<int>arr){
    pair<int,int> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]==arr[i+1]){
            ans.first = arr[i];
        }
        if(i+1 != arr[i] || i+2 == arr[i]){
            ans.second = (i+1==arr[i])?i+1:i+2;
        }
    }
    return ans;
}

pair<int,int> calculateNTime(vector<int>arr){
    int xor1 = arr[0];
    for(int i=1;i<arr.size();i++){
        xor1 = xor1 ^ arr[i];
    }
    for(int i=1;i<=arr.size();i++){
        xor1 = xor1 ^ i;
    }
    int set_bit_no = xor1 & ~(xor1-1);
    int x=0,y=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i] & set_bit_no){
            x = x ^ arr[i];
        }else{
            y = y ^ arr[i];
        }
    }
    for(int i=1;i<=arr.size();i++){
        if(i & set_bit_no){
            x = x ^ i;
        }else{
            y = y ^ i;
        }
    }
    pair<int,int> p(y,x);
    return p;
}


int main(){

    cout<<"Enter Size of Array:->";
    int n;cin>>n;
    vector<int> arr(n,0);
    cout<<"Enter Array Element:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    pair<int,int> ans = calculateNLogN(arr);
    cout<<"repeating element is "<<ans.first<<" missing is "<<ans.second<<"\n";
 
    ans = calculateNTime(arr);
    cout<<"repeating element is "<<ans.first<<" missing is "<<ans.second<<"\n";

}