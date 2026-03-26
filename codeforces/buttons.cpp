#include <iostream>
using ll = long long;
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
        if(c%2){
            a+=(c+1)/2;
        }else{
            a+=(c/2);
        }
        b+=(c/2);
        if(a>b){
            cout<<"First"<<endl;
        }else{
            cout<<"Second"<<endl;
        }
    }
    
    return 0;
}