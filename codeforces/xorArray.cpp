#include <iostream>
using ll = long long;
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;cin>>t;
    while(t--){
        int n,l,r;
        cin>>n>>l>>r;
        int b1 = l-1;
        int b3 = n-r;
        if(b1>0){
            if(!(b1&1)){
                cout<<128<<" ";
                b1--;
            }
            while(b1--){
                cout<<64<<" ";
            }
        }
        int b2=(r-l)+1;
        if(b2>0){
            if((b2&1)){
                cout<<1<<" "<<2<<" "<<3<<" ";
                b2-=3;
            }
            while(b2--){
                cout<<8<<" ";
            }
        }
        if(b3>0){
            if(!(b3&1)){
                cout<<16<<" ";
                b3--;
            }
            while(b3--){
                cout<<32<<" ";
            }
        } 
        cout<<endl;
    }

    
    
    return 0;
}