#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>f((n*n)+1,0);
        for(int i=0;i<n*n;i++){
            int t;
            cin>>t;
            f[t]++;
        }
        if(n==1){
            cout<<"NO"<<endl;
            continue;
        }
        bool fl=0;
        for(int i=1;i<=n*n;i++){
            if(f[i]>n*(n-1)){
                fl=1;
                break;
            }
        }
        if(fl){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
        
    }
    
    return 0;
}