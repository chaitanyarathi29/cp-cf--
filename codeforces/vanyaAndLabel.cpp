#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll MODI=1e9+7;
int main(){

    string s;
    cin>>s;

    ll ans=1;
    int noz=0;
    for(int i=0;i<s.size();i++){
        int val = s[i];
        if(val>47 && val<58){
            val-=48;
        }else{
            if(val>64 && val<91){
                val-=55;
            }else{
                val-=61;
            }
        }
        if(s[i]=='-'){
            val=62;
        }
        if(s[i]=='_'){
            val=63;
        }
        noz += (6 - __builtin_popcount(val));
    }
    cout<<endl;
    for(int i=0;i<noz;i++){
        ans*=3;
        ans%=MODI;
    }
    cout<<ans<<endl;

    return 0;
}