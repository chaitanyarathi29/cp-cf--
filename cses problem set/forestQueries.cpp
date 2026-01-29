#include <iostream>
#include <vector>
using namespace std;

int main(){
        
    int n,q;
    cin >>n >> q;
    vector<vector<char>> forest(n, vector<char>(n));
    vector<vector<int>> prefix(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            cin >> forest[i][j];
            int val=0;
            if(forest[i][j]=='*')
                val=1;
            if(i==0 && j==0){
                prefix[i][j] = val;
            }
            if(i==0 && j!=0){
                prefix[i][j] = prefix[i][j-1] + val;
            }
            if(i!=0 && j==0){
                prefix[i][j] = prefix[i-1][j] + val;
            }
            if(i!=0 && j!=0){
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + val;
            }
        }
    }
    while(q--){
        int x1,y1,x2,y2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--;x1--;y2--;x2--;
        int ans=0;
        ans=prefix[y2][x2];
        if (y1 > 0) 
            ans -= prefix[y1-1][x2];
        if (x1 > 0) 
            ans -= prefix[y2][x1-1];
        if (y1 > 0 && x1 > 0) 
            ans += prefix[y1-1][x1-1];
        cout << ans <<endl;
    }
    
    return 0;
}