#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        long long x,n;
        cin>>x>>n;
        long long rem = n%4;
        if(rem==0){
            cout<<x<<endl;
            continue;
        }
        long long ans=0;
        if(rem==1){
            if(x&1){
                ans=x+(4*(n/4)+1);
            }else{
                ans=x-(4*(n/4)+1);
            }
            cout <<ans<<endl;
            continue;
        }
        if(rem==2){
            if(x&1){
                ans=x-1;
            }else{
                ans=x+1;
            }
            cout <<ans<<endl;
            continue;
        }
        if(rem==3){
            if(x&1){
                ans=x-(4*(n/4)+4);
            }else{
                ans=x+(4*(n/4)+4);
            }
            cout <<ans<<endl;
            continue;
        }
    }

    return 0;
}