#include <iostream>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        long long n,w;
        cin>>n>>w;
        if(w==1){
            cout<<0<<endl;
            continue;
        }
        if(w>n){
            cout<<n<<endl;
            continue;
        }
        cout<<(n/w)*(w-1) + (n%w)<<endl;
    }
    
    return 0;
}