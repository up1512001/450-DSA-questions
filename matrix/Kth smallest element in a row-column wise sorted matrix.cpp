#include<bits/stdc++.h>
using namespace std;
#define v vector
#define pb push_back

int main(){
    v<v<int>> arr;
    cout<<"Enter Row and Column size:\n";
    int r,c;cin>>r>>c;
    cout<<"Enter Matrix:\n";
    for(int i =0;i<r;i++){
        v<int> t;
        for(int j=0;j<c;j++){
            int x;cin>>x;
            t.pb(x);
        }
        arr.pb(t);
    }
    cout<<"Enter K Value :";
    int k;cin>>k;

}
