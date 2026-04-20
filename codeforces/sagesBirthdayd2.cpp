#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll =long long;

int main(){

    int n;cin>>n;
    vector<ll>v(n,0);
    for(auto&it:v){
        cin>>it;
    }    
    sort(v.begin(),v.end());
    
    

    return 0;
}
