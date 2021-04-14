#include"logic.cpp"
using namespace std;

// O(N Log N) and O(N) space
void sol1(){
    vector<pair<ll,ll> > v;
    cout<<"Enter pair number:"<<endl;
    ll n;
    cin>>n;
    cout<<"Enter Pairs:"<<endl;
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        v.pb({x,y});
    }
    sort(v.begin(),v.end());
/*    cout<<"After Sorting:"<<endl;
    for(ll i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
  */  stack<pair<ll,ll> > s;
    s.push({v[0].first,v[0].second});
    for(ll i=1;i<n;i++){
        ll s1 = s.top().first;
        ll e1 = s.top().second;
        ll s2 = v[i].first;
        ll e2 = v[i].second;

        if(e1 < s2){
            s.push({s2,e2});
        }else{
            s.pop();
            e1=max(e1,e2);
            s.push({s1,e1});
        }
    }
    cout<<"Merged Intervals:"<<endl;
    while(!s.empty()){
        cout<<s.top().first<<" "<<s.top().second<<endl;
        s.pop();
    }
}

// O(N Log N) O(1) space
void sol2(){
    vector<pair<ll,ll> > v;
    cout<<"Enter pair number:"<<endl;
    ll n;
    cin>>n;
    cout<<"Enter Pairs:"<<endl;
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        v.pb({x,y});
    }
    sort(v.begin(),v.end());
    ll ind=0;
    for(ll i=1;i<n;i++){
        if(v[i].first <= v[ind].second){
            v[ind].second=max(v[i].second,v[ind].second);
        }else{
            ind++;
            v[ind]=v[i];
        }
    }
    cout<<"Merged Intervals:"<<endl;
    for(ll i=0;i<=ind;i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}

int main(){
    sol2();
}
