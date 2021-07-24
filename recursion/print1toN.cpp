#include<bits/stdc++.h>
using namespace std;

void print(int n){
    // base condition
    if(n==0)
        return;
    // Hypothesis
    print(n-1);
    // induction
    cout<<n<<" ";
}

int main(){
    cout<<"Enter N value:";
    int n;cin>>n;
    print(n);
}
