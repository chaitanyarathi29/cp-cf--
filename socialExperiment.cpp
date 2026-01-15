#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(n==2 || n==3){
            cout<<n<<endl;
            continue;
        }
        if(n%2==0){
            cout<<0<<endl;
            continue;
        }
        cout<<1<<endl;
    }
    return 0;
}