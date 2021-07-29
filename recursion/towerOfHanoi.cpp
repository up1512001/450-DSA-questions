#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n,string sor,string aux,string des){
    if(n==1){
        cout<<"Moving plate "<<n<<" from "<<sor<<" to "<<des<<"\n";
        return;
    }
    towerOfHanoi(n-1,sor,des,aux);
    cout<<"Moving plate "<<n<<" from "<<sor<<" to "<<des<<"\n";
    towerOfHanoi(n-1,aux,sor,des);
    return;
}

int main(){
    cout<<"Enter No of blocks:->";
    int n;cin>>n;

    towerOfHanoi(n,"Source","Auxiliary","Destination");

}
