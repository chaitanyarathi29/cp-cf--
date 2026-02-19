#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int main(){

    int n;cin>>n;
    vector<ll> v(n,0);
    for(auto&it:v){
        cin>>it;
    }
    sort(v.begin(),v.end());
    ll pre=0;ll post=1;
    ll ans=0;
    if(v[0]!=1){
        cout<<1<<endl;
        return 0;
    }else{
        for(int i=1;i<n;i++){
            ll tempre=v[i];ll tempost = post+v[i];
            if(post>=tempre){
                post=tempost;
            }else{
                if(post==tempre-1){
                    post=tempost;
                }else{
                    cout<<post+1<<endl;
                    return 0;
                }
            }
        }
        cout<<post+1<<endl;
    }
    
    return 0;
}