#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){

    vector<int>spf(3001,0);
    for(int i=0;i<spf.size();i++){
        spf[i]=i;
    }
    for(int i=2;i*i<=3001;i++){
        for(int j=i*i;j<=3001;j+=i){
            if(spf[j]==j)spf[j]=i;
        }
    } 
    int n;cin>>n;int ans=0;
    for(int i=2;i<=n;i++){
        int num=i;
        set<int>s;
        while(num!=1){
            s.insert(spf[num]);
            num/=spf[num];
        }

        if(s.size()==2){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}