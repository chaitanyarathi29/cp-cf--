#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

int main(){

    int n;cin>>n;
    vector<ll>vec(n,0);
    for(auto&it:vec){
        cin>>it;
    }
    vector<ll>sorted = vec;
    sort(sorted.begin(),sorted.end());
    vector<ll>vec1(n,0);
    vec1[0]=vec[0];
    vector<ll>vec2(n,0);
    vec2[0]=sorted[0];

    for(int i=1;i<n;i++){
        vec1[i]=vec[i]+vec1[i-1];
    }
    for(int i=1;i<n;i++){
        vec2[i]=sorted[i]+vec2[i-1];
    }
    int m;cin>>m;
    while(m--){
        int t,l,r;
        cin>>t>>l>>r;
        if(t==1){
            if(l==1){
                cout<<vec1[r-1]<<endl;
            }else{
                cout<<vec1[r-1]-vec1[l-2]<<endl;
            }
        }else{
            if(l==1){
                cout<<vec2[r-1]<<endl;
            }else{
                cout<<vec2[r-1]-vec2[l-2]<<endl;
            }
        }
    }

    
    return 0;
}