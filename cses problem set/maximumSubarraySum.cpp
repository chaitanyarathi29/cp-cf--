#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

int main(){

    int n;cin>>n;
    vector<ll>v(n,0);
    bool f=1;
    ll maxi=-1000000000;
    for(auto&it:v){
        cin>>it;
        if(it>=0){
            f=0;
        }
        if(maxi<it){
            maxi=it;
        }
    }
    ll sum=0;
    ll max=-10000000000;
    for(int i=0;i<n;i++){
        sum += v[i];
        if(max<sum){
            max=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    if(f){
        cout<<maxi<<endl;    
    }else{
        cout<<max<<endl;
    }
    
    
    return 0;
}