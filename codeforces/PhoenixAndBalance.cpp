#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a=0,b=0;
        for(int i=1;i<=(n/2)-1;i++){
            a+=(1<<i);
        }
        a+=(1<<n);
        for(int 
            i=n/2;i<n;i++){
            b+=(1<<i);
        }
        cout<<a-b<<endl;
    }
    
    return 0;
}