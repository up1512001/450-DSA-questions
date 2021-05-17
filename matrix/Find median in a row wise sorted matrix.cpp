#include<bits/stdc++.h>
using namespace std;
#define v vector
#define pb push_back

// O(R * C) time and O(N) space
float median1(v<v<int>> arr){
    map<int,int> m;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            m[arr[i][j]]++;
        }
    }
    int n = arr.size()*arr[0].size();
    int ans=0;
    cout<<"Size of Arr :"<<n<<"\n";
    for(auto i=m.begin();i!=m.end();i++){
        cout<<i->first<<" "<<i->second<<"\n";
    }
    auto itr=m.begin();
    if(n%2==1){
        while(itr!=m.end()){
            //if(ans == n/2) return itr->first;
            if(ans < (n/2)+1 && itr->second > 0){
                ans++;
                if(ans == (n/2)+1) return itr->first;
                itr->second-=1;
            }else{
                itr++;
            }
        }
    }else{
        int t=0;
        while(itr!=m.end()){
            //if(ans == n/2) return itr->first;
            //q=itr->first;
            if(ans < (n/2)+1 && itr->second > 0){
                ans++;
                t=itr->first;
                if(ans == (n/2)+1) return float(itr->first+t)/(float)2.0f;
                itr->second-=1;
            }else if(itr->second==0){
                itr++;
            }

        }
    }
    return -1;
}



int main(){
    v<v<int>> arr;
    cout<<"Enter Row And Column Size :\n";
    int r,c;cin>>r>>c;
    for(int i=0;i<r;i++){
        v<int > t;
        for(int j=0;j<c;j++){
            cout<<"Enter Element:\n";
            int x;cin>>x;
            t.pb(x);
        }
        arr.pb(t);
    }
    cout<<"Median Of Arr :"<<median1(arr)<<"\n";
}
