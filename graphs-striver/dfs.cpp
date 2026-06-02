#include <iostream>
#include <vector>
using namespace std;

void dfs(int root, vector<vector<int>>arr, vector<int>& vis){
    
    if(vis[root]){
        return;
    }
    
    for(auto &it: arr[root]){
        if(!vis[it]){
            vis[it]=1;
            dfs(it,arr,vis);
            cout<<it<<" ";
        }
    }
}

int main(){

    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
    }
    vector<int>vis(n+1);
    vis[1]=1;
    cout<<1<<" ";
    dfs(1,arr,vis);

    return 0;
}
