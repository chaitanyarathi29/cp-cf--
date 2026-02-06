#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<long long>v(n,0);
        for(auto&it:v){
            cin>>it;
        }
        long long ans=0;
        for(int i=0;i<n-2;i++){
            if((v[i]+v[i+1])>=(v[i]-v[i+1])){
                ans+=v[i];
            }else{
                ans-=v[i+1];
                v[i+1]=v[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
