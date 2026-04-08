//Find the subarray of size K which has the maximum distinct elements in an
//array.

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
    int max=-1;
    for(int i=0;i<k;i++){
        mp[v[i]]++;
    }
    max=mp.size();
    for(int i=k;i<n;i++){
        mp[v[i-k]]--;
        if(mp[v[i-k]]==0) mp.erase(v[i-k]);
        mp[v[i]]++;
        if(max<mp.size()) max=mp.size();
    }

    cout<<max<<endl;
    
    return 0;
}