#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int mask = n-1;

        vector<pair<int,int>>ans;
        int cnt=0;
        for(int i=0;i<n/2;i++){
            ans.push_back({cnt,(mask^cnt)}); 
            cnt++;
        }
        if(k==n-1){
            if(n==4){
                cout<<-1<<endl;
                continue;
            }
            ans[1].second=3;
            ans[0].first=mask-1;
            ans[3].first=0;
        }else{
            if(k<(n>>1)){
                ans[0].first=k;
                ans[k].first=0;
            }else{
                ans[0].first=k;
                ans[(mask^k)].second=0;
            }
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
    }
    
    return 0;
}