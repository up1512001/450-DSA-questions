#include<bits/stdc++.h>
using namespace std;
#define v vector
#define pb push_back


void print(v<v<int>> &dp){
    cout<<"\nPrinting DP Table:\n";
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[i].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"End Of Table:\n";
}

// real dp
int realDP(v<int>&we,v<int>&val,int n,int w){
    v<v<int>> dp(n+1,v<int>(w+1,-1));
//    memset(dp,0,sizeof(dp));
    cout<<"DP size raw: "<<dp.size()<<" column :"<<dp[0].size()<<"\n";
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=w;i++){
        dp[0][i] = 0;
    }
    print(dp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(we[i-1] <= j){
                dp[i][j] = max(val[i-1]+dp[i-1][j-we[i-1]],dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    print(dp);
    return dp[n][w];
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

//    memset(dp,-1,sizeof(dp));
    cout<<"Maximum Profit : "<<realDP(we,val,n,w);
    //print(dp,n,w);
}

/*

Enter Weight array size :
4
Enter Weight array
1
3
4
6
Enter Value Array
8
4
6
7
Enter Knapsack Maximum Weight holding capacity:
10
Maximum Profit : 14418112
Printing DP Table:
0 0 0 0 0 -1 -1 -1 -1 -1 -1
0 8 8 8 8 -1 -1 -1 -1 -1 -1
0 8 8 8 12 -1 -1 -1 -1 -1 -1
0 8 8 8 12 -1 -1 -1 -1 -1 -1
0 8 8 8 12 -1 -1 -1 -1 -1 -1
End Of Table:

Process returned 0 (0x0)   execution time : 30.281 s
Press any key to continue.


*/
