#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){

        int n,k;
        cin>>n>>k;
        vector<int>v(n,0);
        int ne=0;
        bool f=0;
        int ans=1000002;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(!(v[i]%2)){
                ne++;
            }
            if(!(v[i]%k)){
                f=1;
            }
            ans=min((k-(v[i]%k)),ans);
        }
        if(f){
            cout<<0<<endl;
            continue;
        }
        if(k!=4){
            cout<<ans<<endl;
        }else{
            if(ne==0){
                if(ans>2){
                    cout<<2<<endl;
                }else{
                    cout<<ans<<endl;
                }
                continue;
            }
            if(ne==1){
                cout<<1<<endl;
                
            }
            if(ne>=2){
                cout<<0<<endl;
            }
        }

    }
    
    return 0;
}