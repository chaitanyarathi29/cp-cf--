#include <iostream>
#include <vector>
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
        int val=0;
        for(int i=0;i<n;i++){
            val^=vec[i];
        }
        if(val==0){
            cout<<"YES"<<endl;
            continue;
        }
        int cnt=0;
        int temp=0;
        for(int i=0;i<n;i++){
            temp^=vec[i];
            if(temp==val){
                cnt++;temp=0;
            }
        }
        if(cnt>=3){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
