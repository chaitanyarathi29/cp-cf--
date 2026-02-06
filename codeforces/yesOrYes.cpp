#include <iostream>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        int cnt=0;
        for(auto&it:s){
            if(it=='Y'){
                cnt++;
            }
        }
        if(cnt>1){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}