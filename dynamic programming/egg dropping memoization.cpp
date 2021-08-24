#include<bits/stdc++.h>
using namespace std;

int static dp[11][51];
// constrains
// 0<= egg <= 10
// 0<= floor <= 50

int eggDrop(int e,int f){

    if(f==0 || f==1 || e==1){
        return f;
    }
    if(dp[e][f] != -1){
        return dp[e][f];
    }

    int mn = INT_MAX;
    for(int i=1;i<=f;i++){

        int tempans = 1 + max(eggDrop(e-1,i-1),eggDrop(e,f-i));
        mn = min(mn,tempans);
    }
    dp[e][f] = mn;
    return dp[e][f];

}

int main(){

    memset(dp,-1,sizeof(dp));

    cout<<"Enter number of eggs:->";
    int e;cin>>e;
    cout<<"Enter number of floors:->";
    int f;cin>>f;

    cout<<"Minimum number of attempts are :->"<<eggDrop(e,f)<<"\n";


}
