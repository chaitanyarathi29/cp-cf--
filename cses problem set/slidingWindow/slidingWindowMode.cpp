#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
using ll = long long;

struct custom_compare{
    bool operator()(pair<ll,int>&a, pair<ll,int>&b){

        if(a.second==b.second){
            return (a.first > b.first);
        }
        return (a.second<b.second);
    }
};

int main(){

    int n,k;cin>>n>>k;
    vector<ll>v(n,0);
    for(auto&it:v){
        cin>>it;
    }
    map<ll,int>mp;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,custom_compare>pq;

    for(int i=0;i<k;i++){
        mp[v[i]]++;
    }
    for(auto&it:mp){
        pq.push({it.first,it.second});
    }
    cout<<pq.top().first<<" ";

    for(int i=k;i<n;i++){
        mp[v[i-k]]--;mp[v[i]]++;
        pq.push({v[i-k],mp[v[i-k]]});
        pq.push({v[i],mp[v[i]]});
        while(!pq.empty() && pq.top().second != mp[pq.top().first]){
            pq.pop();
        }
        cout<<pq.top().first<<" ";
    }


    return 0;
}