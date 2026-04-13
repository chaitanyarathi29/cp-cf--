#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct custom_compare{
    bool operator()(pair<ll,ll>&a,pair<ll,ll>&b){
        if(a.first==b.first){
            return (a.second<b.second);
        }
        return (a.first>b.first);
    }
};

int main(){

    int n;cin>>n;
    vector<pair<ll,ll>>v(n);
    for(auto&it:v){
        cin>>it.first>>it.second;
    }
    int cnt=1;
    int maxi=-1;
    sort(v.begin(),v.end());
    for(int i=1;i<n;i++){
        if(v[i].second<v[i-1].second){
            cnt++;
        }else{
            cnt=1;
        }
        maxi=max(cnt,maxi);
    }
    cout<<maxi<<endl;
    
    return 0;
}