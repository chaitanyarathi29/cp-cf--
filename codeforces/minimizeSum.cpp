#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){

    int t;cin>>t;
    while(t--){

        int n;cin>>n;
        vector<ll>vec(n,0);

        for(auto&it:vec){
            cin>>it;
        }
        ll mask=0;
        for(int i=0;i<=30;i++){
            mask=mask|(1<<(30-i));
            int cnt=0;
            for(int i=0;i<n;i++){
                if((mask&vec[i])==mask){
                    cnt++;
                }
            }
            if(cnt<2){
                mask=mask^(1<<(30-i));
            }
        }
        sort(vec.begin(),vec.end());
        int count=0;
        ll ans=0;
        ll val=0;
        for(int i=n-1;i>=0;i--){
            if((mask&vec[i])==mask && count<2){
                val^=vec[i];
                count++;
            }else{
                ans+=vec[i];
            }   
        }
        ans+=val;
        cout<<ans<<endl;
    }
    
    return 0;
}