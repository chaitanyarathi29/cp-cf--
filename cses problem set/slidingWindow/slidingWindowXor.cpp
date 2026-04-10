#include <iostream>
#include <vector>
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
    
    ll xorr=0;ll sum=0;
    for(int i=0;i<k;i++){
        sum^=v[i];
    }
    xorr^=sum;
    for(int i=k;i<n;i++){
        sum^=(v[i-k]^v[i]);
        xorr^=sum;
    }
    cout<<xorr<<endl;

    return 0;
}