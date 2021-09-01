#include<bits/stdc++.h>
using namespace std;

int squareRoot(int n){
/*
    int i=1,j=n/2,ans=INT_MAX,temp=0;
    while(i<=j){
        int mid = i+(j-i)/2;
        if(mid*mid<=n){
            if(ans>(n-mid*mid)){
                ans=n-mid*mid;
                temp=mid;
                if(ans==0){
                    temp--;
                }
            }
        }
        if(mid*mid<n){
            i=mid+1;
        }else{
            j=mid-1;
        }
    }
    cout<<sqrt(n)<<" "<<(int(sqrt(n)))<<"\n";
    return temp;
*/

    if((int(sqrt(n)))==sqrt(n)) return sqrt(n)-1;
    return (int)sqrt(n);

}

int main(){

    cout<<"Enter number to find square root:->";
    int n;cin>>n;

    cout<<"Number Square root before given number:->"<<squareRoot(n)<<"\n";
}
