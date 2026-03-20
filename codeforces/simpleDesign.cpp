#include <iostream>
using ll = long long;
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        ll x;int k;
        cin>>x>>k;
        while(1){
            ll temp=x;
            int s=0;
            while(temp){
                int d=temp%10;
                s+=d;temp/=10;
            }
            if(!(s%k)) break;
            x++;
        }
        cout<<x<<endl;
    }
    
    return 0;
}