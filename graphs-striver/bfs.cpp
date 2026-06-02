#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
    }

    //bfs
    queue<int>q;
    q.push(1);
    vector<bool>vis(n+1);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto&it: arr[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
        cout<<node<<" ";
    }
    
    
    return 0;
}