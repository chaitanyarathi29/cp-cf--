#include <iostream>
using namespace std;
#define ll long long
long long const N = 1e9+7;

ll expo(ll a, ll b){
    if(b==0){
        return 1;
    }
    ll ans=expo(a,b/2);
    ans*=ans;
    ans%=N;
    if(b&1){
        ans*=a;
        ans%=N;
    }
    return ans;
}

int main(){

    int t;cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        long long ans=expo(a,b);
        cout<<ans<<endl;
    }
    return 0;
}