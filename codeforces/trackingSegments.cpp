#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>>v;
        for(int i=0;i<m;i++){
            int f,s;
            cin>>f>>s;
            v.push_back({f,s});
        }
        int q;cin>>q;
        vector<int>x(q,0);
        for(auto&it:x){
            cin>>it;
        }
        int ans=-1;
        int l=1;int h=q;
        while(l<=h){
            int mid = l+(h-l)/2;
            bool f=0;
            vector<int>k(n+1,0);
            for(int i=0;i<mid;i++){
                k[x[i]]=1;
            }
            for(int i=2;i<=n;i++){
                k[i]+=k[i-1];
            }
            for(int i=0;i<m;i++){
                if(k[v[i].second]-k[v[i].first-1]>(v[i].second-v[i].first+1)/2){   
                    f=1;break;
                }   
            }
            if(f){
                ans=mid;h=mid-1;   
            }else{
                l=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}