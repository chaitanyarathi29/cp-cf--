#include <iostream>
#include <vector>
using namespace std;

int main(){

    long long n,t;
    cin>>n>>t;
    vector<int>v(n,0);
    for(auto&it:v){
        cin>>it;
    }
    long long sum = 0;
    long long num = 0;
    for(int i=0;i<n;i++){
        if(v[i]>num){
            sum+=(v[i]-num);
            num = v[i]+100;
        }
    }
    if(t>num){
        sum += (t-num);
    }
    cout<<sum<<endl;

    return 0;
}