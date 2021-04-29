#include<bits/stdc++.h>
using namespace std;
#define v vector
#define pb push_back

class fcfs{

public:
    v<int> wt;
    v<int> tat;
    v<int> bust;
    v<int> pro;
    v<int> wating(v<int> pro,v<int> bust,v<int> wt){
        wt.pb(0);
        for(int i=1;i<pro.size();i++){
            wt.pb(bust[i-1]+wt[i-1]);
        }
        //cout<<wt.size()<<"\n";
        //show(wt);
        return wt;
    }
    v<int> turnaround(v<int> pro,v<int> tat,v<int> wt,v<int> bust){
        for(int i=0;i<pro.size();i++){
            tat.pb(wt[i]+bust[i]);
        }
        return tat;
    }
    void detail(v<int> pro,v<int> bust){
        int tot_w=0,tot_tat=0;
        wt.clear();
        tat.clear();
       // cout<<pro.size();
        wt=wating(pro,bust,wt);
        //cout<<wt.size();
        //show(wt);
        tat=turnaround(pro,tat,wt,bust);
        cout<<"Process||Bust time||Waiting time||Turn around time\n";
        for(int i=0;i<pro.size();i++){
            tot_w+=wt[i];
            tot_tat+=tat[i];
            cout<<"    "<<pro[i]<<"\t   "<<bust[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\n";
        }
        cout<<"Average waiting time:"<<float(tot_w)/(float)pro.size()<<"\n";
        cout<<"Average turn around time:"<<float(tot_tat)/(float)pro.size()<<"\n";
    }
    void show(v<int> arr){
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
};
int main(){
    fcfs a;
    cout<<"Enter total process:\n";
    int n;cin>>n;
    cout<<"Enter Process:\n";
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.pro.pb(x);
    }
    cout<<"Enter Bust:\n";
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.bust.pb(x);
    }
    a.detail(a.pro,a.bust);
}
