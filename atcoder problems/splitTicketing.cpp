#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

int main(){

    int n;cin>>n;
    vector<vector<ll>>v(n+2,vector<ll>(n+2,0));
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            cin>>v[i][j];
        }
    }
    int cnt=1;
    bool f=0;
    for(int i=1;i<n-1;i++){
        int m=i+1;
        for(int j=i+2;j<=n;j++){
            while(m<j){
                if(v[i][j]>v[i][m]+v[m][j]){
                    f=1;break;
                }
                m++;
            }
            m=i+1;
        }
        if(f){
            break;
        }
    }
    if(f){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}