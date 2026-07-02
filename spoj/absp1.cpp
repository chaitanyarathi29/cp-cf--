#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){

    int t;cin>>t;
    while(t--){

        int n; cin>>n;
        vector<ll>v(n,0);
        for(auto&it:v){
            cin>>it;
        }
        vector<ll>prefix(n,0);
        for(int i=0;i<n;i++){
            prefix[i] = v[i];
        }
        for(int i=1;i<n;i++){
            prefix[i] += prefix[i-1];
        }
        ll sum=0;
        for(int i=0;i<n-1;i++){
            ll val = prefix[n-1]-prefix[i];
            sum = sum + (val - 1LL*(v[i])*(n-(i+1)));
        }
        cout<<sum<<endl;

    }
    
    
    return 0;
}