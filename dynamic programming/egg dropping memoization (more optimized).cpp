#include<bits/stdc++.h>
using namespace std;

int static dp[11][51];

int moreOptimizedEggDrop(int e,int f){

    if(f==0 || f==1 || e==1){
        return f;
    }
    if(dp[e][f]!=-1){
        return dp[e][f];
    }

    int mn = INT_MAX;
    for(int i=1;i<=f;i++){
        int b,nb;
        if(dp[e-1][i-1]!=-1){
            b=dp[e-1][i-1];
        }else{
            b=moreOptimizedEggDrop(e-1,i-1);
        }
        if(dp[e][f-i]!=-1){
            nb=dp[e][f-i];
        }else{
            nb=moreOptimizedEggDrop(e,f-i);
        }
        int tempans = 1 + max(b,nb);
        mn = min(mn,tempans);
    }
    dp[e][f] = mn;
    return dp[e][f];

}

int main(){

    memset(dp,-1,sizeof(dp));

    cout<<"Enter number of eggs:->";
    int e;cin>>e;
    cout<<"Enter number of floor:->";
    int f;cin>>f;

    cout<<"minimum number of attempts are :->>"<<moreOptimizedEggDrop(e,f)<<"\n";


}
