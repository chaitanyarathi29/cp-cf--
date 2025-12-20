#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n,0);
        vector<int>b(n,0);
        for(auto&it:a)cin>>it;
        for(auto&it:b)cin>>it;
        vector<int>a1(n,0);
        vector<int>b1(n,0);
        for(int i=0;i<n;i++){
            a1[a[i]-1] = a[i];
            b1[a[i]-1] = b[i];
        }
        for(auto&it:a1)cout<<it<<" ";
        cout<<endl;
        for(auto&it:b1)cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}