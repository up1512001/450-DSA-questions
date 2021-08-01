#include<bits/stdc++.h>
using namespace std;

int josephusProblem(int n,int k,vector<int>&arr,int index=0){

    if(arr.size()==1){
        return arr[0];
    }

    index = (index+k)%arr.size();

    arr.erase(arr.begin()+index);

    josephusProblem(n,k,arr,index);


}

int main(){

    cout<<"Enter N and K Value :\n";
    int n,k;cin>>n>>k;

    vector<int> arr(n);
    for(int i=1;i<=n;i++)
        arr[i-1] = i;

    cout<<"Last Remaining Index is :->"<<josephusProblem(n,k-1,arr)<<"\n";

}
