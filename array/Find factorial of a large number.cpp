#include "logic.cpp"
// in some case this will not work
string factorial(ll n){
    long long i;
    long double sum=0;
    if(n==0)return "1";
    for(i=1;i<=n;i++){
        sum+=log(i);
    }
    string s = to_string(round(exp(sum)));
    return s;

}
#define MAX 1000
// effective method
ll m(ll i,ll res[],ll res_size);
void multiply(ll n){
    ll res[MAX];
    res[0]=1;
    ll res_size=1;
    for(ll i=2;i<=n;i++){
        res_size=m(i,res,res_size);
    }
    for(ll i=res_size-1;i>=0;i--){
        cout<<res[i];
    }
    cout<<endl;
}
ll m(ll i,ll res[],ll res_size){
    ll carry=0;
    for(ll j=0;j<res_size;j++){
        ll prod = res[j]*i+carry;

        res[j] = prod%10;
        carry = prod/10;
    }
    while(carry){
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}


int main(){
    cout<<"Enter number to find factorial:"<<endl;
    ll n;
    cin>>n;
    //cout<<"Your Value:"<<multiply(n)<<endl;
    multiply(n);
}


// other way
/*
// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        return multiply(N);
    }
    //int m(int i,int res[],int res_size);
    vector<int> multiply(int n){
    int res[10000];
    res[0]=1;
    int res_size=1;
    for(int i=2;i<=n;i++){
        res_size=m(i,res,res_size);
    }
    vector<int> ans;
    for(int i=res_size-1;i>=0;i--){
        ans.push_back(res[i]);
    }
    return ans;
    //cout<<endl;
}
int m(int i,int res[],int res_size){
    int carry=0;
    for(int j=0;j<res_size;j++){
        int  prod = res[j]*i+carry;

        res[j] = prod%10;
        carry = prod/10;
    }
    while(carry){
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends


*/
