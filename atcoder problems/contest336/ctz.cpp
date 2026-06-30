#include <iostream>
using namespace std;
using ll = long long;

int main(){

    ll n;cin>>n;
    int cnt=0;
    ll temp=1;
    while(!(n&temp)){
        cnt++;
        temp <<=1;
        temp |=1;
    }
    cout<<cnt<<endl;
    
    return 0;
}