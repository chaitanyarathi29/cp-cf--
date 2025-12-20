#include <iostream>
using namespace std;

long long length(int l,int n){
    if(n==1)
        return l;
    if(n&1){
        return length(l+1,3*n+1);
    }else{
        return length(l+1,n/2);
    }
}

int main(){ 

    int n;
    cin>>n;
    long long ans = length(1,n);
    cout <<ans<<endl;
    return 0;
}