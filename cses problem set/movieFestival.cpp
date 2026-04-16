#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){

    int n;cin>>n;
    vector<pair<ll,ll>>v(n);
    for(auto&it:v){
        cin>>it.first>>it.second;
    }
    sort(v.begin(),v.end(), [](pair<ll,ll>a,pair<ll,ll>b){
        return a.second < b.second;
    });
    ll sec = v[0].second;
    int cnt=1;
    for(int i=1;i<n;i++){
        if(v[i].first>=sec){
            sec=v[i].second;cnt++;
        }
    }   

    cout<<cnt<<endl;

    return 0;
}