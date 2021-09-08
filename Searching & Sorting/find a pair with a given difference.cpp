#include<bits/stdc++.h>
using namespace std;

pair<int,int> optimizedAns(vector<int> arr,int diff){
    int i=0,j=1;
    pair<int,int> ret;
    while(i<arr.size() && j<arr.size()){
        if(i!=j && (arr[j]-arr[i] == diff || arr[i]-arr[j] == diff)){
            ret.first = arr[i];
            ret.second = arr[j];
            return ret;
        }else if((arr[j]-arr[i]) < diff){
            j++;
        }else{
            i++;
        }
    }
    return {-1,-1};
}
pair<int, int> usingSorting(vector<int> arr, int diff){
    sort(arr.begin(),arr.end());
    pair<int,int> ret;
    for(int i=0;i<arr.size();i++){
        int temp = arr[i] + diff;
        int a=0,b=arr.size()-1;
        while(a<=b){
            int mid = a+(b-a)/2;
            if(temp==arr[mid]){
                ret.second = arr[mid];
                ret.first = arr[i];
                return ret;
            }else if(arr[mid]>temp){
                b=mid-1;
            }else{
                a=mid+1;
            }
        }
    }
    return {-1,-1};
}
int main(){

    cout<<"Enter Array Size:->";
    int n;cin>>n;
    vector<int> arr(n,0);
    cout<<"Enter Array:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter Difference :->";
    int diff;cin>>diff;

    pair<int,int> ans = usingSorting(arr,diff);
    cout<<"using sorting :->"<<ans.first<<" "<<ans.second<<"\n";
    ans = optimizedAns(arr,diff);
    cout<<"Optimized approach :->"<<ans.first<<" "<<ans.second<<"\n";

}