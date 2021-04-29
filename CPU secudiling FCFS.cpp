#include<bits/stdc++.h>
#include<iostream>
void wating(int pro[],int n,int bust[],int w[]){
    w[0]=0;
    for(int i=1;i<n;i++){
        w[i]=bust[i-1]+w[i-1];
    }
}
void turnaround(int pro[],int n,int bust[],int w[],int turn[]){
    for(int i=0;i<n;i++){
        turn[i]=bust[i]+w[i];
    }
}
void detail(int pro[],int n,int bust[]){
    int w[n],turn[n],tot_w=0,tot_turn=0;
    wating(pro,n,bust,w);
    turnaround(pro,n,bust,w,turn);
    std::cout<<"process  wating time  turn around time  bust time\n";
    for(int i=0;i<n;i++){
        tot_w+=w[i];
        tot_turn+=turn[i];
        std::cout<<"\t"<<pro[i]<<"\t"<<w[i]<<"\t"<<turn[i]<<"\t"<<bust[i]<<"\n";

    }
    std::cout<<"\n";
    std::cout<<"Average wating time:"<<(float)tot_w/(float)n<<"\n";
    std::cout<<"Average turn around time"<<(float)tot_turn/(float)n;
}

int main(){
    int pro[5]={2,3,5,7,9};
    int n = 5;
    int bust[5]={10,5,9,23,49};
    detail(pro,n,bust);

}
