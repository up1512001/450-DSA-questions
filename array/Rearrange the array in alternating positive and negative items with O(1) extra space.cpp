#include"logic.cpp"
//
void sol(ll arr[],ll n){
    ll i=0,j=n-1;
    while(i<j){
        while(arr[i]>0 && i<n) i++;
        while(arr[j]<0 && j>=0) j--;
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    if(i==0 || i==n-1) return;
    else{
        j=1;
        while(j<n && i<n){
            swap(arr[j],arr[i]);
            i++;
            j+=2;
        }
    }
}

// 0x01 if to check index is odd or even for even index it return 0 and for odd index it will return 1
// O(N^2) time complexity O(1) space
void rightRotate(ll arr[],ll n,ll outofbound,ll i){
    ll temp = arr[i];
    for(ll a=i;a > outofbound;a--){
        arr[a]=arr[a-1];
    }
    arr[outofbound]=temp;
}
void sol2(ll arr[],ll n){
    ll outofbound=-1;
    for(ll i=0;i<n;i++){
        if(outofbound >=0){
            if((arr[i]>=0 && arr[outofbound]<0) || (arr[i]<0 && arr[outofbound]>=0)){
                rightRotate(arr,n,outofbound,i);

                if(i-outofbound>=2){
                    outofbound+=2;
                }else{
                    outofbound=-1;
                }
            }
        }
        if(outofbound == -1){
            if((arr[i]>=0 && !(i & 0x01)) || (arr[i] < 0 && (i & 0x01))){
                outofbound=i;
            }
        }
    }
}

int main(){
    tell;
    ll n; cin>>n;
    ll arr[n];
    enterarray;
    getarray(arr,n);
    sol2(arr,n);
    cout<<"OutPut Array:";
    print(arr,n);
}
