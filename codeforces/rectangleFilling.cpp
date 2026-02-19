#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){

        int n,m;cin>>n>>m;
        vector<vector<char>>v(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
        }
        if(n==0){
            if(v[n][0]==v[n][m-1]){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
            continue;
        }
        if(m==0){
            if(v[0][0]==v[n-1][0]){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
            continue;
        }
        char tl=v[0][0];
        char tr=v[0][m-1];
        char bl=v[n-1][0];
        char br=v[n-1][m-1];
        bool flag=0;
        if(tl==br || tr==bl){
            cout<<"Yes"<<endl;
        }else{
            if(tl==tr){
                for(int i=1;i<m;i++){
                    if(v[0][i-1]!=v[0][i]){
                        cout<<"Yes"<<endl;
                        flag=1;
                        break;
                    }
                }
                if(flag){
                    continue;
                }
                for(int i=1;i<m;i++){
                    if(v[n-1][i-1]!=v[n-1][i]){
                        cout<<"Yes"<<endl;
                        flag=1;
                        break;
                    }
                }
                if(flag){
                    continue;
                }
            }
            if(tl==bl){
                for(int i=1;i<n;i++){
                    if(v[i-1][0]!=v[i][0]){
                        cout<<"Yes"<<endl;
                        flag=1;
                        break;
                    }
                }
                if(flag){
                    continue;
                }
                for(int i=1;i<n;i++){
                    if(v[i-1][m-1]!=v[i][m-1]){
                        cout<<"Yes"<<endl;
                        flag=1;
                        break;
                    }
                }
                if(flag){
                    continue;
                }
            }
            cout<<"No"<<endl;
        }
    }
    return 0;
}