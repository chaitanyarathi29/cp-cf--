#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<vector<int>>vec(n,vector<int>(n,0));
    vector<vector<int>>vis(n,vector<int>(n,0));
    vis[n/2][n/2]=2;

    vector<pair<int,int>>dir;
    dir.push_back({0,1});
    dir.push_back({-1,0});
    dir.push_back({0,-1});
    dir.push_back({1,0});
    int ans=1;
    int cnt=0;
    int visited=0;
    int i=n-1;int j=0;
    bool flag=0;
    int direction=0;
        while (true) {
            if (vis[i][j] == 2) {
                break;
            }
    
            vec[i][j] = ans;
            ans++;
            vis[i][j] = 1;
    
            int nextrow = i + dir[direction].first;
            int nextcol = j + dir[direction].second;
    
            if (nextrow >= 0 && nextrow < n &&
                nextcol >= 0 && nextcol < n &&
                vis[nextrow][nextcol] != 1) {
                
                i = nextrow;
                j = nextcol;
            } 
            else {
                direction = (direction + 1) % 4;
    
                i += dir[direction].first;
                j += dir[direction].second;
            }
        }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]==2){
                cout<<"T"<<" ";    
            }else{
                cout<<vec[i][j]<<" ";
            }
        }   
        cout<<endl;
    }

    return 0;
}