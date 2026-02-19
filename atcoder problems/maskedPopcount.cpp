#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll const mod = 998244353;

int main(){

    ll n,m;
    cin>>n>>m;
    vector<ll>f(61,0);
    ll sum=0;
    for(int i=0;i<61;i++){
        if(n>=(1LL<<i)){
            ll val = n/(1LL<<i);
            if((val&1)){
                sum+=n%(1LL<<i)+1;
                sum%=mod;
            }
            val/=2;
            sum += val*((1LL<<i));
            sum%=mod;
            f[i]=sum;
            sum=0;
        }
    }
    ll num=1;
    ll ans=0;
    int j=0;
    while(num<=m){
        if(m&num){
            ans += f[j];
            ans%=mod;
        }
        j++;
        num=(1LL<<j);
    }
    cout<<ans<<endl;
    
    return 0;
}