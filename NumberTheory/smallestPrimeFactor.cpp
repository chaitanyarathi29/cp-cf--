#include <iostream>
#include <vector>
using namespace std;

int main(){    
    vector<int>spf(200,0);
    for(int i=0;i<spf.size();i++){
        spf[i]=i;
    }
    for(int i=2;i*i<=200;i++){
        for(int j=i*i;j<=200;j+=i){
            spf[j]=i;
        }
    } // nlog(logn) precomputation
    vector<int>prime;
    int n;cin>>n;
    while(n!=1){
        prime.push_back(spf[n]);
        if(n%spf[n]==0){
            n/=spf[n];
        }
    } //logn finding complexity
    return 0;
}