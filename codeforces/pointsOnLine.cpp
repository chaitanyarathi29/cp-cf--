#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

int main(){

    int n;cin>>n;
    ll d;cin>>d;
    vector<ll>v(n,0);
    for(auto&it:v){
        cin>>it;
    }
    ll last = v[n-1];
    ll cnt=0;
    for(int i=0;i<n;i++){
        ll add = v[i]+d;
        int idx = upper_bound(v.begin(),v.end(),add)-v.begin();
        --idx;
        int s = idx-i-1;
        if(s==0) continue;
        if(s==1) {cnt++;continue;}
        cnt+=(1LL*s*(s+1))/2;
    }   
    cout<<cnt<<endl;

    return 0;
}