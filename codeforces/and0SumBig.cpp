#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define mod (long long)(1e9+7);

long long helper(long long n, long long k){
    if(k==0)return 1;
    long long ans=helper(n,k-1);
    ans%=mod;
    ans*=n;
    ans%=mod;
    return ans;
}
int main(){
    int t;
    cin >>t;
    while(t--){
        long long  n,k;
        cin >>n>>k;
        cout <<helper(n,k)<<endl;
    }

    return 0;
}