#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>a(n,0);
        vector<int>a1(n,0);
        for(auto&it:a)cin>>it;
        for(auto&it:a1)cin>>it;
        int l=0;int r=0;
        for(int i=0;i<n-1;i++){
            if(a[i]!=a1[i]){
                l=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(a[i]!=a1[i]){
                r=i;
                break;
            }
        }
        while(l>0 && a1[l]>=a1[l-1]){
            l--;
        }
        while(r<n-1 && a1[r]<=a1[r+1]){
            r++;
        }
        cout<<l+1<<" "<<r+1<<endl;
    }
    
    return 0;
}