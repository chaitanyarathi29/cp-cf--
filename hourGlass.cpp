#include <iostream>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        long long  s,k,m;
        cin>>s>>k>>m;
        long long rem = m%k;
        if(s>=k){
            if((m/k)%2==0){
                cout<<s-(rem)<<endl;
                continue;
            }else{
                cout<<k-rem<<endl;
                continue;
            }
        }else{
            cout<<s-min(rem,s)<<endl;
            continue;
        }
    }
    return 0;
}