#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    vector<pair<int,pair<int,int>>>day;
    int cnt=0;
    map<int,int>mp;

    for(int i=1;i<=n;i++){
        int a,d,b;
        cin>>a>>d>>b;

        day.push_back({d,{a,b}});

        if(mp[a]==0){
            cnt++;
        }
        mp[a]++;
    }
    vector<int>ans(m+1,-1);
    ans[0]=cnt;
    sort(day.begin(),day.end());
    for(int i=0;i<day.size();i++){
        int a = day[i].second.first;
        int b = day[i].second.second;
        int d = day[i].first;
        
        mp[a]--;
        if(mp[a]==0){
            cnt--;
        }
        mp[b]++;
        if(mp[b]==1){
            cnt++;
        }
        ans[d]=cnt;
    }

    for(int i=1;i<=m;i++){
        if(ans[i]==-1){
            ans[i]=ans[i-1];
        }
        cout<<ans[i]<<endl;
    }
    
    return 0;
}