#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        long long n;cin>>n;
        long long ans=0;
        for(int i=0; i<62;i++){
            long long num = n/(1LL<<i);
            ans+=num;
        }
        cout<<ans<<endl;
    }

    return 0;
}