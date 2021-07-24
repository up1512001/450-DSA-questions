#include<bits/stdc++.h>

using namespace std;

void print(int n){

    // base condition
    if(n==0)
        return;
    // induction
    cout<<n<<" ";
    print(n-1);

}

int main(){
    cout<<"Enter N Value:";
    int n;cin>>n;

    print(n);
}
