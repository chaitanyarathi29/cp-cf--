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
    
    

    return 0;
}