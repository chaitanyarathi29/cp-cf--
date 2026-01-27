#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<long long >v(n,0);
        for(auto&it:v){
            cin>>it;
        }
        vector<long long>sorted = v;
        sort(sorted.begin(),sorted.end());
        vector<long long>ans;
        long long min=1e9+2;
        for(int i=0;i<n;i++){
            if(sorted[i]!=v[i]){
                ans.push_back(v[i]);
            }
            if(min>=v[i]){
                min=v[i];
            }
        }
        long long num=0;
        if(ans.size()>0){
            num=ans[0];
            for(int i=1;i<ans.size();i++){
                num = gcd(num,ans[i]);
            }
        }else{
            cout<<"Yes"<<endl;
            continue;
        }
        if(num%min==0){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    
    return 0;
}