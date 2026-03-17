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
        int max=v[0];
        int cnt=1;
        for(int i=1;i<n;i++){
            if(v[i]>=max){
                cnt++;
                max=v[i];
            }
        }
        cout<<cnt<<endl;
    }
    
    return 0;
}