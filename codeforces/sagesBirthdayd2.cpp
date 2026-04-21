#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll =long long;

int main(){

    int n;cin>>n;
    vector<ll>v(n,0);
    for(auto&it:v){
        cin>>it;
    }    
    sort(v.begin(),v.end());
    
    vector<ll>ans(n,0);
    int j=0;
    for(int i=1;i<n;i+=2){
        ans[i]=v[j];j++;
    }
    for(int i=0;i<n;i+=2){
        ans[i]=v[j];j++;
    }
    int cnt=0;
    for(int i=1;i<n-1;i++){
        if(ans[i]<ans[i-1] && ans[i]<ans[i+1]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    for(auto&it:ans){
        cout<<it<<" ";
    }

    return 0;
}
