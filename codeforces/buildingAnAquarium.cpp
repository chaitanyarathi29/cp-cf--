#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

bool helper(ll h,ll x,vector<ll>v){
    ll temp=x;
    for(auto&it:v){
        if(h>it){
            temp-=(h-it);
        }
    }
    return (temp>=0);
}

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        ll x;cin>>x;
        vector<ll>v(n,0);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        ll si=0;ll ei=1e12;ll ans=-1;
        while(si<=ei){
            ll mid = si + (ei-si)/2;
            if(helper(mid,x,v)){
                ans=mid;
                si=mid+1;
            }else{
                ei=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}