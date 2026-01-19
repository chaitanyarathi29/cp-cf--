#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>v(n,0);
        for(auto&it:v){
            cin>>it;
        }
        bool flag=true;
        for(int i=0;i<n-2;i++){
            for(int j=i+2;j<n;j+=2){
                if(v[i]==v[j]+1 || v[i]==v[j]-1){
                    flag=false;
                    break;
                }
                if(!flag){
                    break;
                }
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}