#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        ll n,c,k;
        cin>>n>>c>>k;
        vector<ll>v(n,0);
        bool f=0;
        for(auto&it:v){
            cin>>it;
            if(it<=c){
                f=1;
            }
        }
        sort(v.begin(),v.end());
        if(!f){
            cout<<c<<endl;
        }else{
            for(int i=0;i<n;i++){
                if(c>v[i]){
                    if(k<(c-v[i])){
                        c+=v[i]+k;k=0;
                    }else{
                        k-=(c-v[i]);c+=c;
                    }
                    continue;
                }
                if(c==v[i]){
                    c+=c;
                }
            }
            cout<<c<<endl;
        }
    }
    
    return 0;
}