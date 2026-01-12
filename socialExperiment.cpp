#include <iostream>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(n==2 || n==3){
            cout<<n<<endl;
            continue;
        }
        if(n%2==0 || n%3==0){
            cout<<0<<endl;
            continue;
        }
        if(n%3==1){
            cout<<3<<endl;
            continue;
        }
        if(n%2==1){
            cout<<1<<endl;
            continue;
        }
    }


    return 0;
}