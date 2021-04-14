#include "logic.cpp"
/*
// O(N + M) time and O(1) space
ll sol(ll arr1[],ll arr2[],ll n,ll m){
    ll i=0,j=0,m1=-1,m2=-1;
    if((m+n)%2 ==1){
        for(ll cnt=0;cnt<=(m+n)/2;cnt++){
            if(i!=n && j!=m){
                m1 = (arr1[i]>arr2[j] ? arr2[j++]:arr1[i++]);
            }else if(i<n){
                m1 = arr1[i++];
            }else{
                m1 = arr2[j++];
            }
        }
        return m1;
    }else{
        for(ll cnt=0;cnt<=(m+n)/2;cnt++){
            m2=m1;
            if(i!=n && j!=m){
                m1 = (arr1[i]>arr2[j] ? arr2[j++]:arr1[i++]);
            }else if(i<n){
                m1 = arr1[i++];
            }else{
                m1 = arr2[j++];
            }
        }
    }
    return (m1 + m2)/2;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    tell;
    ll n;cin>>n;
    ll arr1[n];
    enterarray;
    getarray(arr1,n);
    tell;
    ll m;cin>>m;
    enterarray;
    ll arr2[m];
    getarray(arr2,m);

    cout<<"Median of two sorted array :"<<sol(arr1,arr2,n,m)<<endl;
}
*/



double median(ll a[],ll n){
    if(n%2==0){
        return (double(a[n/2]+a[n/2-1]))/2;
    }
    return double(a[n/2]);
}

double find_median(ll a1[],ll a2[],ll n){
    if(n==0)return -1;
    if(n==1)return double((a1[0]+a2[0]))/2;
    if(n==2)return double((max(a1[0],a2[0])+min(a1[1],a2[1])))/2;

    double m1 = median(a1,n);
    double m2 = median(a2,n);

    if(m1==m2)return m1;
    if(m1<m2){
        if(n%2==0) return find_median(a1+n/2-1,a2,n-n/2+1);
        return find_median(a1+n/2,a2,n-n/2);
    }
    if(n%2==0) return find_median(a2+n/2-1,a1,n-n/2+1);
    return find_median(a2+n/2,a1,n-n/2);
}

int main(){
    tell;
    ll n;
    cin>>n;
    enterarray;
    ll arr1[n];
    getarray(arr1,n);
    //tell;
   // ll m;cin>>m;
    enterarray;
    ll arr2[n];
    getarray(arr2,n);

    cout<<"Median of Given Arrays:"<<find_median(arr1,arr2,n);

}











