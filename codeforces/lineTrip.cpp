#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int>v(n,0);
        for(auto&it:v){
            cin>>it;
        }
        int maxx=v[0];
        for(int i=1;i<n;i++){
            maxx = max(maxx,v[i]-v[i-1]);
        }
        maxx = max(maxx,2*(x-v[n-1]));
        cout<<maxx<<endl;
    }   

    return 0;
}