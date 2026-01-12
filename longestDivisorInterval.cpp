#include <iostream>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        long long n;cin>>n;
        int cnt=0;
        for(long long i=1;i<=n;i++){
            if(n%i==0){
                cnt++;
            }else{
                break;
            }
        }
        cout<<cnt<<endl;
    }
    
    return 0;
}