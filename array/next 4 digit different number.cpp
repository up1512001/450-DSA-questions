#include<bits/stdc++.h>
using namespace std;
#define ll long long int
/* void ans(vector<ll >a,ll n){
    ll x=n,i=0;
    while(x>0){
        a[i]=x%10;
        x/=10;
        i++;
    }
}
bool differ(vector<ll>a){
    for(ll i=0;i<a.size();i++){
        for(ll j=0;j<a.size();j++){
            if(a[i]==a[j] && i!=j){
                return false;
            }
        }
    }
    return true;
}
*/
int main(){
    ll n;
    cin>>n;
  //  vector<ll>a;
    //bool v=false;
    while(1){
        n++;
        ll a=n/1000;
        ll b=(n/100)%10;
        ll c=(n/10)%10;
        ll d=(n%10);
        if(a!=b && a!=b && a!=c && a!=d && b!=c && b!=d && c!=d){
            break;
        }
    }
    cout<<n<<endl;

}
