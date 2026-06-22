#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n,s,k;
    cin>>n>>s>>k;
    int ans=0;
    while(n--){
        int p,q;
        cin>>p>>q;
        ans += (p*q);
    }
    if(ans<s){
        ans+=k;
    }
    cout<<ans<<endl;
    
    return 0;
}