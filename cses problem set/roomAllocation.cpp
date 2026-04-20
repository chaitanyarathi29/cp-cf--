#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){

    int n;cin>>n;
    vector<pair<int,int>>v(n);
    for(auto&it:v){
        cin>>it.first>>it.second;
    }
    sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
        return a.second < b.second;
    });
    queue<pair<int,int>>q;
    vector<int>ans;
    int cnt=1;
    for(int i=0;i<n;i++){
        if(q.empty() || q.front().first >= v[i].first){
            q.push({v[i].second,cnt});
            ans.push_back(cnt);
            cnt++;
        }else{
            int room = q.front().second;
            q.pop();
            ans.push_back(room);
            q.push({v[i].second,room});
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<n;i++){
        
    }

    return 0;
}