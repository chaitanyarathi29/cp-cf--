#include <iostream>
using namespace std;

long long highestPowerOf2(long long n) {
    long long res = 1;
    while (res <= n)
        res <<= 1;
    return res >> 1; 
}

int main(){

    int ans=0;
    long long x;
    cin>>x;
    while(x!=0){
        long long hp = highestPowerOf2(x);
        x -= hp;
        ans++;
    }
    cout << ans;

    return 0;
}