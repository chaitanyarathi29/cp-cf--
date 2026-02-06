#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        long long n;cin>>n;
        long long ans1,ans2=0;
        vector<long long>fac = {1};
        for(long long i=2;i*i<=n;i++){
            if(n%i==0){
                fac.push_back(i);
            }
            if(i!=(n/i)){
                fac.push_back(n/i);
            }
        }
        cout<<endl;
        long long mini=1e10;
        for(int i=0;i<fac.size();i++){
            if(mini>lcm(fac[i],n-fac[i])){
                mini=lcm(fac[i],n-fac[i]);
                ans1=fac[i];
                ans2=n-fac[i];
            }
        }
        cout<<ans1<<" "<<ans2<<endl;
    }


    return 0;
}