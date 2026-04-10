// Given an array of N elements, find out the length of the longest subarray
// with number of distinct elements <= K

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
    int l,r;l=r=0;
    map<int,int>mp;
    int max=-1;
    while(l<n && r<n){
        mp[v[r]]++;
        while(mp.size()>k){
            mp[v[l]]--;
            if(mp[v[l]]==0) mp.erase(v[l]);
            l++;
        }
        if(max<r-l+1){
            max=r-l+1;
        }
        r++;
    }
    cout<<max<<endl;

    return 0;
}