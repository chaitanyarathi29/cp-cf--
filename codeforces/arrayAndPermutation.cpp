#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>p(n,0);
        for(auto&it:p){
            cin>>it;
        }
        vector<int>a(n,0);
        for(auto&it:a){
            cin>>it;
        }
        vector<int>idx(n+1,0);
        for(int i=0;i<n;i++){
            idx[p[i]]=i;
        }
        int cnt=0;
        bool flag=1;
        for(int i=0;i<n-1;i++){
            if(a[i]!=a[i+1]){
                if(idx[a[i]]>idx[a[i+1]]){
                    flag=0;
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
