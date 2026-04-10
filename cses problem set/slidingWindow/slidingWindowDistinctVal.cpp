#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){

    int n,k;cin>>n>>k;
    vector<int>v(n,0);
    for(auto&it:v){
        cin>>it;
    }
    map<int,int>mp;
    for(int i=0;i<k;i++){
        mp[v[i]]++;
    }
    cout<<mp.size()<<" ";
    for(int i=k;i<n;i++){
        mp[v[i-k]]--;
        if(mp[v[i-k]]==0) mp.erase(v[i-k]);
        mp[v[i]]++;
        cout<<mp.size()<<" ";
    }
    cout<<endl;
    return 0;
}