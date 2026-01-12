#include <iostream>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int s,k,m;
        cin>>s>>k>>m;
        if(s==k){
            if(m%k==0){
                cout<<s<<endl;
                continue;
            }
            cout<<(s%k)<<endl;
        }
        if(s>k){
            if(k>m){
                cout<<0<<endl;
                continue;
            }
            if(m%k==0){
                cout<<k<<endl;
                continue;
            }
            cout<<m%k<<endl;
        }   
        if(s<k){
            
        }
    }

    return 0;
}