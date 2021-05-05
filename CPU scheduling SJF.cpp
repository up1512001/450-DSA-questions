#include<bits/stdc++.h>
using namespace std;
#define v vector
#define pb push_back
#define p pair
class SJF{
public:
    v<v<int> > arr;
    v<v<int>> arrange(v<v<int>> a){
        // this function will sort according to arrival time
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a.size()-i-1;j++){
                if(a[j][1]>a[j+1][1]){
                    for(int k=0;k<5;k++){
                        swap(a[j][k],a[j+1][k]);
                    }
                }
            }
        }
        return a;
    }
    /*
    v<v<int>> wating(v<v<int>> a){
        a[0][3]=0;

        for(int i=1;i<a.size();i++){
            a[i-1][3]=(a[i][2]+a[i-1][3]);
        }
        return a;
    }
    v<v<int>> turnaroundtime(v<v<int>> a){
        for(int i=0;i<a.size();i++){
            a[i][4]=(a[i][2]+a[i][3]);
        }
        return a;
    }
    */
    void compute(){
        arr = arrange(arr);
        //pri(arr);

        //arr=wating(arr);
        //arr = turnaroundtime(arr);

        int temp,val;
        arr[0][3] = arr[0][1]+arr[0][2];
        arr[0][5]=arr[0][3]-arr[0][1];
        arr[0][4]=arr[0][5]-arr[0][2];
        for(int i=1;i<arr.size();i++){
            temp = arr[i-1][3];
            int low = arr[i][2];
            for(int j=i;j<arr.size();j++){
                if(temp>=arr[j][1] && low>=arr[j][2]){
                    low = arr[j][2];
                    val=j;
                }
            }
            arr[val][3]=temp+arr[val][2];
            arr[val][5]=arr[val][3]-arr[val][1];
            arr[val][4]=arr[val][5]-arr[val][2];
            for(int j=0;j<6;j++){
                swap(arr[val][j],arr[i][j]);
            }
        }
        int tot_wt=0,tot_tat=0;
        cout<<"Process||Arrival||Bust||Waiting||Turn Around\n";
        for(int i=0;i<arr.size();i++){
            tot_wt+=arr[i][4];
            tot_tat+=arr[i][5];
            cout<<"  "<<arr[i][0]<<"\t  "<<arr[i][1]<<"\t   "<<arr[i][2]<<"\t  "<<arr[i][4]<<"\t  "<<arr[i][5]<<"\n";
        }
        pri(arr);
        cout<<"Average Waiting Time:->"<<(float)tot_wt/(float)arr.size()<<"\n";
        cout<<"Average Turn Around Time:->"<<(float)tot_tat/(float)arr.size()<<"\n";
    }
    void pri(v<v<int>> a){
        for(int i=0;i<a.size();i++){
            cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<" "<<a[i][3]<<" "<<a[i][4]<<" "<<a[i][5]<<"\n";
        }
    }
};
int main(){
    SJF a;
    cout<<"Enter Total number of Process:\n";
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter Process:";
        int x;cin>>x;
        cout<<"\nEnter Arrival Time:";
        int y;cin>>y;
        cout<<"\nEnter Bust Time:";
        int z;cin>>z;
        a.arr.pb({x,y,z,0,0,0});
    }
    a.compute();
}
