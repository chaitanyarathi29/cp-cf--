#include <iostream>
#include <vector>
using namespace std;

const int MAXN=1e5+2;
int main(){

    int n,k;
    cin>>n>>k;
    vector<int>spf(MAXN,0);
    for(int i=2;i<spf.size();i++){
        spf[i]=i;
    }
    for(int i=2;i*i<spf.size();i++){
        for(int j=i*i;j<=spf.size();j+=i){
            if(spf[j]==j) spf[j]=i;
        }
    }
    vector<int>ans;
    while(k>1 && n>1){
        ans.push_back(spf[n]);
        n/=spf[n];
        k--;
    }
    if(k==1 && n>1){
        ans.push_back(n);
    }else{
        cout<<-1<<endl;
        return 0;
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}