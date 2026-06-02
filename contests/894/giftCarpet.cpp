#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;


    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>>v(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }   
        }
        bool f=0;
        string name="vika";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int k=0;
                
            }   
        }
        if(f){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    
    
    return 0;
}