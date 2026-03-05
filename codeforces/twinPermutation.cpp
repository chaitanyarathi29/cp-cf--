#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>a(n,0);
        for(auto&it:a){
            cin>>it;
        }
        for(int i=0;i<n;i++){
            cout<<(n+1)-a[i]<<" ";
        }
        cout<<endl;
    }
}