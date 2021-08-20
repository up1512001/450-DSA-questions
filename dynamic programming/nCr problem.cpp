// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // long long int min(long long int a,long long int b){
    //     return a>b?a:b;
    // }
    // 778 116
    // excpeted :->735309323
    // my output:->-1850942752
    int nCr(int n, int r){
        // code here
        if(n<r) return 0;
        long dp[r+1];
        dp[0] =1;
        for(int i=1;i<=r;i++) dp[i] = 0;
        for(int i=1;i<=n;i++){
            for(int j=min(i,r);j>0;j--){
                dp[j] = (dp[j]+dp[j-1])%1000000007;
            }
        }
        
        return dp[r];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends
