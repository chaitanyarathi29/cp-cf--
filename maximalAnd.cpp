#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>v(n,0);
        for(auto&it:v)cin>>it;
        vector<int>cnt(31,0);
        int ans=0;
        for(int i=30;i>=0;i--){
            int temp=0;
            for(int j=0;j<n;j++){
                if((v[j]&(1<<i))>0){
                    temp++;
                }
            }
            cnt[i]=n-temp;
        }
        for(int i=30;i>=0;i--){
            if(cnt[i]<=k){
                k-=cnt[i];
                ans|=(1<<i);
            }
        }
        cout <<ans<<endl;
        
    }

    return 0;
}