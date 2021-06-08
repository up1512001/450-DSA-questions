 #include<bits/stdc++.h>
 using namespace std;
 #define v vector
 #define pb push_back

 void firstFit(v<int> &pS,v<int>&bS){
    v<int> alloc(pS.size(),-1);
    for(int i=0;i<pS.size();i++){
        for(int j=0;j<bS.size();j++){
            if(bS[j] >= pS[i]){
                alloc[i]=j;
                bS[j] -= pS[i];
                break;
            }
        }
    }
    cout<<"Process ID||Process Size||Block ID\n";
    for(int i=0;i<pS.size();i++){
        cout<<"   "<<i+1<<"\t\t"<<pS[i]<<"\t\t";
        if(alloc[i]!=-1) cout<<alloc[i]+1;
        else cout<<"Not Allocated";
        cout<<"\n";
    }
 }

 int main(){
    v<int> pSize;
    v<int> bSize;
    cout<<"Enter Total Number of Processes:\n";
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter Process Size: ";
        int p;cin>>p;
        pSize.pb(p);
    }
    cout<<"Enter Total Number Block Size:\n";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter Block Size: ";
        int b;cin>>b;
        bSize.pb(b);
    }
    firstFit(pSize,bSize);
 }
