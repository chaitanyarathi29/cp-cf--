#include <iostream>
#include <cmath>
using ll = long long;
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        ll n,k,g;
        cin>>n>>k>>g;
        ll save=min((n-1)*((g-1)/2),k*g);
        ll rem=k*g-save;
        ll r=rem%g; 
        if(r>=(g+1)/2){
            save-=(g-r);
        }else{
            save+=r;
        }
        cout<<save<<endl;
    }
    
    return 0;
}