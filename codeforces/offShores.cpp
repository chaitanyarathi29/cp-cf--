#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        long long x,y;
        cin>>x>>y;
        long long tm = 0;
        long long ans = 0;
        vector<long long>v(n,0);
        for(auto&it:v){
            cin>>it;
            tm+=it/x;
            ans=max(ans,it);
        }
        for(int i=0;i<n;i++){
            long long fm = v[i]+(y*(tm-(v[i]/x)));
            ans=max(ans,fm);
        }
        cout<<ans<<endl;
    }
    
    return 0;
}