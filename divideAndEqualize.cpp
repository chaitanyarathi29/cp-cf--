#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>v(n,0);
        long long prod=1;
        for(auto&it:v){
            cin>>it;
            prod*=it;
        }
        double num = pow(prod,1/n);
        int val = num;
        double ans = num-val;
        if(ans!=0){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}