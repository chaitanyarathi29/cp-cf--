#include <iostream>
using namespace std;

long long digit(long long y) {
    long long s=0;
    while(y>0){
        s+=y%10;
        y/=10;
    }
    return s;
}
int main(){
    int t;cin>>t;
    while(t--){
        long long x;cin>>x;
        int count=0;
        for (long long y=x+1;y<x+100;y++) {
            if(y-digit(y)==x){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
