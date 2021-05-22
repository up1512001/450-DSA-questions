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

// time O(32 * R * log(C)) space O(1)
float binaryMedian(v<v<int>> arr){
    int min=INT_MAX,max=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(min>arr[i][0]) min=arr[i][0];
        if(max<arr[i][arr[i].size()-1]) max=arr[i][arr[i].size()-1];
    }
    cout<<"Min:"<<min<<" Max:"<<max<<"\n";
    int desired = (arr.size()*arr[0].size()+1)/2;
    while(min<max){
        int mid = min + (max-min)/2;
        int place = 0;
        for(int i=0;i<arr.size();i++){
            // upper_bound will also include mid value also
            place+=upper_bound(arr[i].begin(),arr[i].end(),mid)-arr[i].begin();
        }
        if(place < desired){
            min=mid+1;
        }else{
            max=mid;
        }
    }
    return min;
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
    cout<<"Median Of Arr :"<<binaryMedian(arr)<<"\n";
}
