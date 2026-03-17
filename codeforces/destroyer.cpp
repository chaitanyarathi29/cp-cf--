#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>v(101,0);
        while(n--){
            int l;cin>>l;
            v[l]++;
        }
        bool f=1;
        for(int i=1;i<101;i++){
            if(v[i]>v[i-1]){
                f=0;
                break;
            }
        }
        if(f){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}