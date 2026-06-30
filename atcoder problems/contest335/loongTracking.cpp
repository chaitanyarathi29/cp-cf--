#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){

    int n,q;
    cin>>n>>q;
    vector<pair<int,int>>v;
    map<char,pair<int,int>>mp;
    mp['R']={1,0};
    mp['D']={0,-1};
    mp['U']={0,1};
    mp['L']={-1,0};
    for(int i=n;i>0;i--){
        v.push_back({i,0});
    }
    while(q--){
        int a;
        cin>>a;
        int size = v.size();
        if(a==1){
            char b;
            cin>>b;
            v.push_back({v[size-1].first+mp[b].first,v[size-1].second+mp[b].second});
        }else{
            int k;cin>>k;
            cout<<v[v.size()-k].first<<" "<<v[v.size()-k].second<<endl;
        }
    }
    
    
    return 0;
}