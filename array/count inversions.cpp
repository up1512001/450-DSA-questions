#include "logic.cpp"

// brute force O(N)
void sol1(){
    tell;
    ll n;
    cin>>n;
    enterarray;
    ll arr[n];
    getarray(arr,n);

    ll inv=0;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                inv++;
            }
        }
    }
    cout<<inv<<endl;
}

// O(N Log N)
/*
ll merge(ll arr[],ll l,ll mid,ll r){
    ll inv=0;
    ll n1=mid-l+1;
    ll n2=r-mid;
    ll a[n1];
    ll b[n2];
    for(ll i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(ll i=0;i<n2;i++){
        b[i]=arr[mid+i+1];
    }
    ll i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            arr[k++]=a[i++];
        }else{
            arr[k]=b[j];
            inv+=n1-i;
            k++;j++;
        }
    }
    while(i<n1){
        arr[k++]=a[i++];
    }
    while(j<n2){
        arr[k++]=b[j++];
    }
    return inv;
}

ll mergeSort(ll arr[],ll l,ll r){
    ll inv=0;
    if(l<r){
        ll mid=(l+r)/2;
        inv=mergeSort(arr,l,mid);
        inv+=mergeSort(arr,mid+1,r);
        inv+=merge(arr,l,mid,r);
    }
    return inv;
}
*/
// solution three O(N Log N) O(N) space

ll merge(ll arr[],ll temp[],ll left,ll mid,ll right){
    ll i,j,k,inv=0;
    i=left;
    j=mid;
    k=left;

    while((i<=mid-1) && (j<=right)){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
            inv+=(mid-i);
        }
    }

    while(i<=mid-1){
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]=arr[j++];
    }

    for(ll m=left;m<=right;m++){
        arr[m]=temp[m];
    }
    return inv;
}

ll mergeSort(ll arr[],ll temp[],ll left,ll right){
    ll inv=0;
    if(left < right){
        ll mid = (left+right)/2;

        inv += mergeSort(arr,temp,left,mid);
        inv += mergeSort(arr,temp,mid+1,right);
        inv += merge(arr,temp,left,mid+1,right);

    }
    return inv;
}

void sol3(){
    tell;
    ll n;
    cin>>n;
    enterarray;
    ll arr[n];
    getarray(arr,n);
    ll temp[n];
    cout<<"Inversion:"<<mergeSort(arr,temp,0,n-1)<<endl;

}

int main(){
    sol3();
}
