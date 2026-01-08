#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const long long MAXN = 1e6+2;

int main(){

    int n;cin>>n;
    vector<long long>v(n,0);
    for(auto&it:v){
        cin>>it;
    }
    vector<long long>spf(MAXN,0);
    for(int i=2;i<MAXN;i++){
        spf[i]=i;
    }
    for(int i=2;i*i<MAXN;i++){
        for(int j=i*i;j<MAXN;j+=i){
            if(spf[j]==j) spf[j]=i;
        }
    }

    for(int i=0;i<v.size();i++){
        long long num = llround(sqrtl(v[i]));
        if(spf[num]==num && num*num==v[i]){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}