#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n,k,p,m;
        cin>>n>>k>>p>>m;
        vector<int>a(n,0);
        vector<int>sorted;
        vector<int>first;
        int j=1;
        int winp=0;
        for(int i=0;i<n;i++){
            int tem;cin>>tem;
            a[i]=tem;
            if(p!=j){
                sorted.push_back(tem);
            }else{
                winp=tem;
            }
            if(j<p){
                first.push_back(tem);
            }
            j++;
        }
        if(n==k){
            cout<<(m/winp)<<endl;
        }else{
            sort(sorted.begin(),sorted.end());
            sort(first.begin(),first.end());
            int sumfirst=0;
            int sumnext=0;
            for(int i=0;i<p-k;i++){
                sumfirst+=first[i];
            }
            for(int i=0;i<n-k;i++){
                sumnext+=sorted[i];
            }
            int ans=0;
            int cnt=m;
            if(p>k){
                cnt-=sumfirst+winp;
            }else{
                cnt-=winp;
            }
            if(cnt>=0){
                ans++;
            }else{
                cout<<0<<endl;
                continue;
            }
            ans+=cnt/(sumnext+winp);
            cout<<ans<<endl;
        }
    }

    return 0;
}