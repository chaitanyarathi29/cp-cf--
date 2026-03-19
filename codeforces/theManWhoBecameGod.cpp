#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>v(n,0);
        for(auto&it:v){
            cin>>it;
        }
        vector<int>d(n-1,0);
        for(int i=1;i<n;i++){
            d[i-1]=abs(v[i]-v[i-1]);
        }
        sort(d.begin(),d.end());
        int cnt=0;
        for(int i=0;i<(n-k);i++){
            cnt+=d[i];
        }
        cout<<cnt<<endl;
    }
    
    return 0;
}