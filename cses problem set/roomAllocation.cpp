#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int main(){

    int n;cin>>n;
    vector<pair<int,int>>v,v1(n);
    for(auto&it:v1){
        cin>>it.first>>it.second;
    }
    v=v1;
    sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
        return a.second < b.second;
    });
    
    
}