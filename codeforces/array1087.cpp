#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<ll>v(n,0);
        for(auto&it:v){
            cin>>it;
        }
        int g=0;int l=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(v[i]>v[j]){
                    g++;
                }
                if(v[i]<v[j]){
                    l++;
                }
            }
            cout<<max(g,l)<<" ";
            g=0;l=0;
        }
        cout<<endl;
    }
    
    return 0;
}