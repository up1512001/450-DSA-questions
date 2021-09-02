#include<bits/stdc++.h>
using namespace std;
#define square(x) ((x)*(x))
#define ESP 1e-6

double dist(pair<int,int> p,double X,double Y){
    return sqrt(square(X-p.first)+square(Y-p.second));
}

double calculate(vector<pair<int,int>>&arr,int a,int b,int c,double val){

    double ret=0;
    double Y = -1 * (c+a*val)/(double)b;
    for(int i=0;i<arr.size();i++){
        ret += dist(arr[i],val,Y);
 //       cout<<"ret :"<<ret<<"\n";
    }
    return ret;
}

double minDist(vector<pair<int,int>>&arr,int a,int b,int c){

    double low = -1e6;
    double high = 1e6;

    while((high-low)>ESP){
        double mid1 = low + (high-low) / 3;
        double mid2 = high - (high-low) / 3;

        double dist1 = calculate(arr,a,b,c,mid1);
        double dist2 = calculate(arr,a,b,c,mid2);

        if(dist1 < dist2){
            high = mid2;
        }else{
            low = mid1;
        }
        //cout<<"low :"<<(float)low<<" high :"<<(float)high<<" high-low:"<<high-low<<"\n";
    }
    return calculate(arr,a,b,c,(low+high)/2.0);

}

int main(){

    cout<<"Enter Number of Points:->";
    int n;cin>>n;
    vector<pair<int,int>> arr(n);
    cout<<"Enter each pair coordinates:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        cin>>arr[i].second;
    }

    cout<<"a , b and c value of line ax + by + c = 0:\n";
    int a,b,c;
    cin>>a>>b>>c;
    //cout<<arr.size()<<"\n";
    cout<<"Minimum distance from given line is :->"<<minDist(arr,a,b,c)<<"\n";

}

/*
5
-3
-2
-1
0
-1
2
1
2
3
4
1
-1
-3

*/
