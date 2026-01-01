#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;cin>>n;
    int m=n+1;
    vector<int>spf(m+1,1);
    for(int i=0;i<spf.size();i++){
        spf[i]=i;
    }
    int cnt=2;
    for(int i=2;i*i<=m;i++){
        for(int j=i*i;j<=m;j+=i){
            if(spf[j]==j){
                spf[j]=i;
            }
        }
    }
    vector<int>ans(m+1,1);
    bool flag=0;
    for(int i=2;i<=m;i++){
        if(spf[i]==i){
            ans[i]=1;
        }else{
            ans[i]=2;
            flag=1;
        }
    }
    if(flag){
        cout<<2<<endl;
    }else{
        cout<<1<<endl;
    }
    for(int i=2;i<=m;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}