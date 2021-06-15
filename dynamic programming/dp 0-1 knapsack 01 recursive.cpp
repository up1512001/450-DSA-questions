#include<bits/stdc++.h>
using namespace std;
#define v vector
#define pb push_back
// recursive solution
int recursive(v<int>&we,v<int>&val,int w,int n){
    if (n==0 || w==0) return 0;
    if(we[n-1] <= w){
        return max(val[n-1]+recursive(we,val,w-we[n-1],n-1),recursive(we,val,w,n-1));
    }else if(we[n-1] > w){
        return recursive(we,val,w,n-1);
    }
    return 0;
}
int main(){
    cout<<"Enter Weight array size :\n";
    int n;cin>>n;
    cout<<"Enter Weight array \n";
    v<int> we;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        we.pb(x);
    }
    cout<<"Enter Value Array \n";
    v<int> val;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        val.pb(x);
    }
    cout<<"Enter Knapsack Maximum Weight holding capacity:\n";
    int w;cin>>w;
    cout<<"Maximum Profit : "<<recursive(we,val,w,n);
    //v<v<int>> dp[n+1][w+1];
    //memset(dp,-1,sizeof(dp));
    //cout<<"Maximum Profit : "<<memorized(dp,we,val,w,n);
}

/*
||=== Build file: "no target" in "no project" (compiler: unknown) ===|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01.cpp||In function 'int memorized(std::vector<std::vector<int> >&, std::vector<int>&, std::vector<int>&, int, int)':|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01.cpp|22|error: invalid initialization of reference of type 'std::vector<std::vector<int> >&' from expression of type 'std::vector<int>'|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01.cpp|16|note: in passing argument 1 of 'int memorized(std::vector<std::vector<int> >&, std::vector<int>&, std::vector<int>&, int, int)'|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01.cpp|22|error: invalid initialization of reference of type 'std::vector<std::vector<int> >&' from expression of type 'std::vector<int>'|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01.cpp|16|note: in passing argument 1 of 'int memorized(std::vector<std::vector<int> >&, std::vector<int>&, std::vector<int>&, int, int)'|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01.cpp|24|error: invalid initialization of reference of type 'std::vector<std::vector<int> >&' from expression of type 'std::vector<int>'|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01.cpp|16|note: in passing argument 1 of 'int memorized(std::vector<std::vector<int> >&, std::vector<int>&, std::vector<int>&, int, int)'|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01.cpp||In function 'int main()':|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01.cpp|48|error: invalid initialization of non-const reference of type 'std::vector<std::vector<int> >&' from an rvalue of type 'std::vector<std::vector<int> > (*)[(((ssizetype)w) + 1)]'|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01.cpp|16|note: in passing argument 1 of 'int memorized(std::vector<std::vector<int> >&, std::vector<int>&, std::vector<int>&, int, int)'|
||=== Build failed: 4 error(s), 0 warning(s) (0 minute(s), 2 second(s)) ===|


*/

