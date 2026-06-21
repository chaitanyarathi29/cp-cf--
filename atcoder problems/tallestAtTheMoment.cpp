#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){

    int n;cin>>n;

    vector<pair<ll,ll>>hei(n);
    vector<ll>ub;
    map<ll,ll>mp;
    ll maxi=-1;
    for(auto&it:hei){
        cin>>it.first>>it.second;
    }
    for(int i=n-1;i>=0;i--){
        ub.push_back(hei[i].second-1);
        maxi=max(maxi,hei[i].first);
        mp[hei[i].second-1]=maxi;
    }

    sort(ub.begin(),ub.end());
    int q;cin>>q;

    while(q--){
        ll t;cin>>t;
        int idx = lower_bound(ub.begin(),ub.end(),t)-ub.begin();
        cout<<mp[ub[idx]]<<endl;
    }   
    
    return 0;
}