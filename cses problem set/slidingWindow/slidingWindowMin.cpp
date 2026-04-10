#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main(){

    ll n,k;
    cin>>n>>k;

    ll x,a,b,c;
    cin>>x>>a>>b>>c;

    vector<ll>v(n,0);
    v[0]=x;

    for(int i=1;i<n;i++){  
        v[i]=((a*v[i-1])+b)%c;
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

    ll xorr=0;
    for(int i=0;i<k;i++){
        pq.push({v[i],i});
    }
    xorr^=pq.top().first;

    for(int i=k;i<n;i++){
        while(!pq.empty() && pq.top().second<i-k+1){
            pq.pop();
        }
        pq.push({v[i],i});
        xorr^=pq.top().first;
    }
    cout<<xorr<<endl;

    return 0;
}