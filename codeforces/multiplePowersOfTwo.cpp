#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main(){
    
    long long n,q;
    cin>>n>>q;
    vector<long long>v(n,0);
    for(auto&it:v)cin>>it;
    long long maxi=32;
    while(q--){
        long long x;
        cin>>x;
        if(x>=maxi){
            continue;
        }
        for(int i=0;i<n;i++){
            if((v[i]&((1<<x)-1))==0){
                v[i] += ((1<<x)-1);
            }
        }
    }
    for(auto&it:v){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}