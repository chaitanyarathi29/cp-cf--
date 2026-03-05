#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){

        int n;cin>>n;
        vector<int>p(n,0);
        for(auto&it:p){
            cin>>it;
        }
        int idx1=-1;
        int idx2=-1;
        int idxn=-1;
        int ans1=-1;int ans2=-1;
        for(int i=0;i<n;i++){
            if(p[i]==2){
                idx2=i+1;
            }
            if(p[i]==1){
                idx1=i+1;
            }
            if(p[i]==n){
                idxn=i+1;
            }
        }
        if(idx2>idx1){
            if(idxn>idx1){
                if(idxn>idx2){
                    ans1=idx2;ans2=idxn;
                }else{
                    ans1=idx2;ans2=idx2;
                }
            }else{
                ans1=idx1;ans2=idxn;
            }
        }else{
            if(idxn>idx2){
                if(idxn>idx1){
                    ans1=idx1;ans2=idxn;
                }else{
                    ans1=idx2;ans2=idx2;
                }
            }else{
                ans1=idx2;ans2=idxn;
            }
        }
        
        cout<<ans1<<" "<<ans2<<endl;
    }
    
    
    return 0;
}