#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){

        int n;cin>>n;
        vector<int>a(n,0);
        vector<int>b(n,0);
        for(auto&it:a){
            cin>>it;
        }
        for(auto&it:b){
            cin>>it;
        }
        vector<int>fa(2*n+1,0);
        vector<int>fb(2*n+1,0);
        int cnt=1;
        fa[a[0]]=1;fb[b[0]]=1;
        for(int i=1;i<n;i++){
            if(a[i-1]==a[i]){
                cnt++;
                if(fa[a[i]]<cnt){
                    fa[a[i]]=cnt;    
                }
            }else{
                cnt=1;
            }
            if(fa[a[i]]<cnt){
                fa[a[i]]=cnt;    
            }
        }
        cnt=1;
        for(int i=1;i<n;i++){
            if(b[i-1]==b[i]){
                cnt++;
            }else{
                cnt=1;
            }
            if(fb[b[i]]<cnt){
                fb[b[i]]=cnt;    
            }
        }
        int max=-1;
        for(int i=1;i<2*n+1;i++){
            if(fa[i]+fb[i]>max){
                max=fa[i]+fb[i];
            }
        }
        cout<<max<<endl;
    }
    
    
    return 0;
}