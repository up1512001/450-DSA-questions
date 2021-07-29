#include<bits/stdc++.h>
using namespace std;

int check(int n,int temp){

    if(n==0){
        return temp;
    }

    temp = (temp*10) + (n%10);

    return check(n/10,temp);

}


int main(){

    cout<<"Enter Number to check if palindrome or not :->";
    int n;cin>>n;

    if(check(n,0)==n){
        cout<<"The number is palindrome\n";;
    }else{
        cout<<"The number is NOT palindrome\n";
    }


}
