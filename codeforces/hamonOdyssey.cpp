#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<ll>v(n,0);
        for(auto&it:v){
            cin>>it;
        }
        ll aand=v[0];
        for(int i=1;i<n;i++){
            aand&=v[i];
        }
        int cnt=0;
        if(aand>0){
            cout<<1<<endl;
            continue;
        }else{
            ll annd=(1LL<<40)-1;
            for(int i=0;i<n;i++){
                annd&=v[i];
                if(annd==0){
                    if(i<n-1){
                        annd=v[i+1];
                    }
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;

    }


    return 0;
}