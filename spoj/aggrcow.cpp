#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

bool helper(vector<ll>&vec, ll mid, int c){
    int x = vec[0];
    for(int i=1;i<c;i++){
        auto it = lower_bound(vec.begin(),vec.end(),x+mid);
        if(it == vec.end()){
            return false;
        }
        x = *it;
    }
    return true;
}

int main(){

    int t;cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        
        vector<ll>vec(n,0);
        for(auto&it:vec){
            cin>>it;
        }

        sort(vec.begin(),vec.end());
        ll low=0,high=1e10;
        ll ans=0;
        while(low<=high){
            ll mid = low + (high-low)/2;

            if(helper(vec,mid,c)){
                ans = max(ans,mid);
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}