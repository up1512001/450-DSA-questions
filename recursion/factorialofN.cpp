#include<bits/stdc++.h>
using namespace std;

int factorial(int n){

    // base condition
    if(n<=0)
        return 1;
    return factorial(n-1)*n;

}

int main(){
    cout<<"Enter N Value:";
    int n;cin>>n;

    cout<<"Factorial of "<<n<<" is :->"<<factorial(n);
}
