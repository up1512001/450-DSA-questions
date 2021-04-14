#include "logic.cpp"

// simple linear approach O(N + M) time and O(1) space complexity
double median(ll a1[],ll a2[],ll n,ll m){
    ll i=0,j=0;
    double m1=-1,m2=-1;
    if((n+m)%2==1){
        for(ll count=0;count<=(n+m)/2;count++){
            if(i!=n && j!=m){
                m1 = (a1[i]>a2[i])?a2[j++]:a1[i++];
            }else if(i<n){
                m1 = a1[i++];
            }else{
                m1 = a2[j++];
            }
        }
        return m1;
    }else{
        for(ll count=0;count<=(n+m)/2;count++){
            m2=m1;
            if(i!=n && j!=m){
                m1 = (a1[i]>a2[i])?a2[j++]:a1[i++];
            }else if(i<n){
                m1 = a1[i++];
            }else{
                m1 = a2[j++];
            }
        }
        return (m1+m2)/2;
    }
}

// Optimal approach O(min(LOG N , LOG M)) time and O(1) space

double MO2(ll a,ll b){
    return (a+b)/2.0;
}
double MO3(ll a,ll b,ll c){
    return a+b+c-max(a,max(c,b))-min(a,min(b,c));
}
double MO4(ll a,ll b,ll c,ll d){
    return (a+b+c+d-max(a,max(b,max(c,d)))-min(a,min(b,min(c,d))))/2.0;
}
double medianSingle(ll a1[],ll n){
    if(n==0){
        return -1;
    }
    if(n%2==0){
        return (double)(a1[n/2]+a1[n/2-1])/2;
    }
    return a1[n/2];
}
double findMedianUtil(ll a1[],ll n,ll a2[],ll m){
    if(n==0){
        return medianSingle(a2,m);
    }
    if(n==1){
        if(m==1){
            return MO2(a1[0],a2[0]);
        }
        if(m & 1){
            return MO2(a2[m/2],MO3(a1[0],a2[m/2-1],a2[m/2+1]));
        }
        return MO3(a2[m/2],a2[m/2-1],a1[0]);
    }
    else if (n==2){
        if(m==2){
            return MO4(a1[0],a1[1],a2[0],a2[1]);
        }
        if(m & 1){
            return MO3(a2[m/2],max(a1[0],a2[m/2-1]),min(a1[1],a2[m/2+1]));
        }
        return MO4(a2[m/2],a2[m/2-1],max(a1[0],a2[m/2-2]),min(a1[1],a2[m/2+1]));
    }
    ll ind1 = (n-1)/2;
    ll ind2 = (m-1)/2;

    if(a1[ind1]<=a2[ind2]){
        return findMedianUtil(a1+ind1,n/2+1,a2,m-ind1);
    }
    return findMedianUtil(a1,n/2+1,a2+ind1,m-ind1);
}
double findMedian(ll a1[],ll n,ll a2[],ll m){
    if(n>m){
        return findMedianUtil(a2,m,a1,n);
    }
    return findMedianUtil(a1,n,a2,m);
}



int main(){
    tell;
    ll n;cin>>n;
    ll a1[n];
    enterarray;
    getarray(a1,n);
    ll m;
    tell;
    cin>>m;
    enterarray;
    ll a2[m];
    getarray(a2,m);

    //cout<<"Median of arrays :"<<median(a1,a2,n,m)<<endl;
    cout<<"Median is :"<<findMedian(a1,n,a2,m)<<endl;
}

