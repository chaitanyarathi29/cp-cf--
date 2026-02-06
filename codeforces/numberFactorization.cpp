#include <iostream>
#include <map> 
using namespace std;

#define ll long long 

int main(){

    ll t;
    cin>>t;
    while(t--){
        ll n;
        ll x=1;
        cin>>n;
        map<ll,ll>ma;
        for(ll i=2;i*i<=n;i++){ //sqrt(n)
            if(n%i==0){
                ll cnt=0;
                while(n%i==0){
                    n/=i;
                    cnt++;
                }
                ma[i]=cnt;
                x=max(x,cnt);
            }
        }
        if(n!=1){
            ma[n]=1;
        }
        ll ans=0;
        for(ll j=1; j<=x;j++){
            ll product=1;
            for(auto it=ma.begin();it!=ma.end();it++){
                if(it->second>0){
                    ma[it->first]--;
                    product*=it->first;
                }
            }
            ans+=product;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}

// int t;cin>>t;
//     while(t--){
//         int n;cin>>n;
//         int x=0;
//         map <int,int> mp;
//         for(int i=2;i<=n;i++){
//             int cnt=0;
//             while(n%i==0){
//                 n/=i;
//                 cnt++;
//             }
//             mp[i]=cnt;
//             x=max(x,cnt);
//         }
//         ll prod=0;
//         ll ans=0;
//         for(int j=1;j<=x;j++){
//             prod=1;   
//             for(auto it=mp.begin();it!=mp.end();){
//                 if(it->second > 0) {
//                     prod *= it->first;
//                     it->second--;
//                 }
//                 if(it->second == 0) {
//                     it = mp.erase(it);  
//                 } else {
//                     ++it;              
//                 }
//             }

//             if(prod>1){
//                 ans+=prod;
//             }
//         }
//         cout<<ans<<endl;
//     }