#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>v(n,0);
        for(auto&it:v){
            cin>>it;
        }
        if(v[0]==0 && v[n-1]==0){
            cout<<"BOB"<<endl;
        }else{
            cout<<"ALICE"<<endl;
        }
    }

    return 0;
}