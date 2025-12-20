#include <iostream>
using namespace std;

long long fac(int n){
    if(n==0)return 1;
    return fac(n-1)*n;
}

int main(){

    int n;
    cin>>n;
    long long ans = fac(n);
    cout<<ans<<endl;
    return 0;
}